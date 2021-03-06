/*
 * This file is part of Neural network Creator, backpropagation
 * simulator and multilayer neural network IDE.
 * Copyright (C) 2013  Petr Kačer <kacerpetr@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cmath>
#include <QDebug>
#include <QApplication>
#include "BpAlgSt.h"

namespace NeuralNetwork{

///////////////////////////////////////////////
///// Public //////////////////////////////////
///////////////////////////////////////////////

/**
 * Creates unconfigured learning configuration.
 */
BpAlgSt::BpAlgSt() : AbstractLrnAlg(),
  updateInterv(10),
  stopIter(1000),
  stopErrorVal(0.01),
  stopTimeVal(2000),
  running(false),
  net(NULL),
  data(NULL),
  actTime(0),
  actIter(0),
  actError(1)
{}

/**
 * Copy constructor of learning algorithm.
 */
BpAlgSt::BpAlgSt(BpAlgSt& obj) : AbstractLrnAlg(),
  updateInterv(obj.updateInterv),
  stopIter(obj.stopIter),
  stopErrorVal(obj.stopErrorVal),
  stopTimeVal(obj.stopTimeVal),
  running(obj.running),
  net(obj.net),
  data(obj.data),
  actTime(obj.actTime),
  actIter(obj.actIter),
  actError(obj.actError)
{
	genDeltaArray();
}

/**
 * Copy constructor from pointer.
 */
BpAlgSt::BpAlgSt(BpAlgSt* obj) : AbstractLrnAlg(),
  updateInterv(obj->updateInterv),
  stopIter(obj->stopIter),
  stopErrorVal(obj->stopErrorVal),
  stopTimeVal(obj->stopTimeVal),
  running(obj->running),
  net(obj->net),
  data(obj->data),
  actTime(obj->actTime),
  actIter(obj->actIter),
  actError(obj->actError)
{
	genDeltaArray();
}

void BpAlgSt::setNetwork(AbstractMlnNet* net){
	this->net = net;
	if(net != NULL) genDeltaArray();
}

void BpAlgSt::setDataset(Dataset* data){
	this->data = data;
}

void BpAlgSt::setUpdateInterval(int interval){
	Q_ASSERT(interval >= 1);
	this->updateInterv = interval;
}

void BpAlgSt::setStopIteration(int stopIter){
	Q_ASSERT(stopIter >= 1);
	this->stopIter = stopIter;
}

void BpAlgSt::setStopError(double stopErr){
	this->stopErrorVal = stopErr;
}

void BpAlgSt::setStopTime(long stopTime){
	Q_ASSERT(stopTime >= 1);
	this->stopTimeVal = stopTime;
}

void BpAlgSt::setAlpha(double alpha){
	this->alphaVal = alpha;
}

AbstractMlnNet* BpAlgSt::network(){
	return net;
}

Dataset* BpAlgSt::dataset(){
	return data;
}

int BpAlgSt::updateInterval() const{
	return updateInterv;
}

int BpAlgSt::stopIteration() const{
	return stopIter;
}

double BpAlgSt::stopError() const{
	return stopErrorVal;
}

long BpAlgSt::stopTime() const{
	return stopTimeVal;
}

bool BpAlgSt::isRunning() const{
	return running;
}

int BpAlgSt::currentIteration() const{
	return actIter;
}

double BpAlgSt::currentError() const{
	return actError;
}

long BpAlgSt::currentTime() const{
	return actTime;
}

double BpAlgSt::alpha() const{
	return alphaVal;
}

/**
 * Class destructor.
 */
BpAlgSt::~BpAlgSt(){}

///////////////////////////////////////////////
///// Slots ///////////////////////////////////
///////////////////////////////////////////////

void BpAlgSt::start(){
	Q_ASSERT(net != NULL);
	Q_ASSERT(data != NULL);

    emit started();

    //value initialization
	running = true;
    actIter = 1;
	actTime = 0;
	timer.restart();

    double sumErr = 0;
    for(int i = 0; i < data->minPatternCount(); i++){
        output = net->layerOutput(data->inputVector(i));
        sumErr += calcError(i);
    }
    actError = sumErr;
    emit update(0, actTime, actError);

    //learning main cycle
	while(running){
		for(int i = 0; i < data->minPatternCount(); i++){
			//feedforward
			output = net->layerOutput(data->inputVector(i));
			//output layer delta calculation
			calcOutputDelta(i);
			//inner layer delta calculation
			calcInnerDelta();
			//weight adjustment
			adjustWeight();
		}

		//current time
		actTime = timer.elapsed();

        //output error calculation
        double sumErr = 0;
        for(int i = 0; i < data->minPatternCount(); i++){
            output = net->layerOutput(data->inputVector(i));
            sumErr += calcError(i);
        }
        actError = sumErr;

        //emits update signal once per each update interval
        if(actIter % updateInterv == 0){
            emit update(actIter, actTime, actError);
        }

        //stop conditions
		if(actTime >= stopTimeVal) break;
		if(actIter >= stopIter) break;
		if(actError <= stopErrorVal) break;

		actIter++;
	}

	//running flag to false
	running = false;

    //signal that tells that learning is finished
    emit stoped();
}

void BpAlgSt::stop(){
	running = false;
}

///////////////////////////////////////////////
///// Private /////////////////////////////////
///////////////////////////////////////////////

/**
 * Calculates network error for one training pattern.
 * E = 0.5 * sum[i = 0 ... out_count](y_i - t_i)^2
 */
double BpAlgSt::calcError(int pattern){
	double err = 0.0;
	for(int i = 0; i < output.last().length(); i++){
		double val = data->output(pattern,i) - output.last()[i];
		err += val*val;
	}
	return 0.5 * err;
}

/**
 * Calculates deltas of neurons in output layer.
 * For all output neurons: delta = (t - y) * f'(bias + sum(inner_layer_outs * weights))
 */
void BpAlgSt::calcOutputDelta(int pattern){
	int l = net->layerCount() - 1;
	for(int n = 0; n < net->neuronCount(l); n++){
		double sum = 0.0;
		for(int w = 0; w < (*net)[l][n].weightCount(); w++){
			sum += output[l][w] * (*net)[l][n][w];
		}
		sum += (*net)[l][n].bias();
		delta[l][n] = (data->output(pattern,n) - output[l+1][n]) * (*net)[l][n].trFcnD(sum);
	}
}

/**
 * Calculates deltas of neurons in inner layers.
 * For all neurons in inner layer L: delta = sum(delta_[L+1] * weight_[L+1]) * f'(bias + sum(layer_[L-1]_outs * neuron_[L,n]_weight))
 */
void BpAlgSt::calcInnerDelta(){
	//over all inner layers
	for(int l = net->layerCount()-2; l >= 0; l--){
		//over all neurons in inner layer
		for(int n = 0; n < net->neuronCount(l); n++){
			//first sum
			double sum1 = 0.0;
			for(int m = 0; m < (*net).neuronCount(l+1); m++){
				sum1 += delta[l+1][m] * (*net)[l+1][m][n];
			}
			//second sum
			double sum2 = 0.0;
			for(int w = 0; w < (*net)[l][n].weightCount(); w++){
				sum2 += output[l][w] * (*net)[l][n][w];
			}
			sum2 += (*net)[l][n].bias();
			//delta calculation
			delta[l][n] = sum1 * (*net)[l][n].trFcnD(sum2);
		}
	}
}

/**
 * Adjusts weights of network according to actual training pattern.
 * For all neurons N in all layers L: delta_Bias = alpha * delta[L,N]; delta_W = alpha * delta[L,N] * weight[L,N,W]
 */
void BpAlgSt::adjustWeight(){
	//over all layers
	for(int l = net->layerCount()-1; l >= 0; l--){
		//over all neurons in layer
		for(int n = 0; n < net->neuronCount(l); n++){
			//alpha * delta (support value)
			double k = delta[l][n] * alphaVal;
			//over all weights of neuron
			for(int w = 0; w < (*net)[l][n].weightCount(); w++){
				//updates weight value
				(*net)[l][n][w] += k * output[l][w];
			}
			//updates bias value
			(*net)[l][n].addBias(k);
		}
	}
}

/**
 * Generates data structure to store deltas of neurons.
 */
void BpAlgSt::genDeltaArray(){
	delta.clear();
	for(int i = 0; i < net->layerCount(); i++){
		delta.append(QList<double>());
		for(int j = 0; j < net->neuronCount(i); j++){
			delta[i].append(0.0);
		}
	}
}

}
