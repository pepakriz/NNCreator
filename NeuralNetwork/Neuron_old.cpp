/*
 * This file is part of neuron network experimental implementation.
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
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2012 Petr Kacer (kacerpetr@gmail.com)
 */

#include "Neuron_old.h"
#include <QStringList>
#include "math.h"
#include "Exception.h"

namespace NeuralNetwork{

Neuron_old::Neuron_old(void) : bias(0), trFcn(HYPERBOLIC_TANGENS){}

Neuron_old::Neuron_old(const Neuron_old& neuron) : bias(neuron.bias), trFcn(neuron.trFcn), weight(neuron.weight){}

Neuron_old::Neuron_old(QString str){
	// default values used when empty string
	if(str.isEmpty() || str == "[]"){
		bias = 0;
		trFcn = HYPERBOLIC_TANGENS;
		return;
	}

	// bracket error
	if(str[0] != '[' || str[str.length()-1] != ']'){
		throw(Exception(NeuronParseError, "(missing bracket in string + \"" + QString(str) + "\")"));
	}

	QString str2 = str.mid(1, str.length()-2);
	QStringList num = str2.split(" ");

	bool ok = true;

	trFcn = (TransferFunction)num[0].toInt(&ok);
	if(!ok)	throw(Exception(NeuronParseError, "(unable to parse transfer function in string + \"" + QString(str) + "\")"));
	if(num.length() == 1) return;

	bias = num[1].toDouble(&ok);
	if(!ok)	throw(Exception(NeuronParseError, "(unable to parse bias in string + \"" + QString(str) + "\""));

	for(int i = 2; i < num.length(); i++){
		appendWeight(num[i].toDouble(&ok));
	}
	if(!ok)	throw(Exception(NeuronParseError, "(in string \"" + QString(str) + "\")"));
}

double Neuron_old::getBias(void)const {
	return bias;
}

void Neuron_old::setBias(double bias){
	this->bias = bias;
}

double Neuron_old::getWeight(unsigned int index) const{
	return weight.at(index);
}

void Neuron_old::setWeight(unsigned int index, double value){
	weight.replace(index, value);
}

double Neuron_old::removeWeight(unsigned int index){
	return weight.takeAt(index);
}

void Neuron_old::insertWeight(unsigned int index, double value){
	weight.insert(index, value);
}

QList<double> Neuron_old::getWeights(void) const{
	return weight;
}

void Neuron_old::setWeights(const QList<double>& weight){
	this->weight = weight;
}

void Neuron_old::appendWeight(double value){
	this->weight.append(value);
}

TransferFunction Neuron_old::getTransferFunction(void) const{
	return trFcn;
}

void Neuron_old::setTransferFunction(const TransferFunction trFcn){
	this->trFcn = trFcn;
}

QString Neuron_old::toString(void){
	if(weight.empty()) return "[" + QString::number(trFcn) + " " + QString::number(bias, 'f', 10) + "]";
	QString result = "[" + QString::number(trFcn) + " " + QString::number(bias, 'f', 10) + " ";
	QList<double>::iterator wg = weight.begin();
	while(wg != --weight.end()){
		result += QString::number(*wg, 'f', 10) + " ";
		wg++;
	}
	result += QString::number(*wg, 'f', 10) + "]";
	return result;
}

Neuron_old Neuron_old::fromString(QString str){
	return Neuron_old(str);
}

double Neuron_old::transferFcn(double x) const{
	switch(trFcn){
		case NOT_LINEAR:
			return x >= 1 ? 1 : 0;
		case SATURATED_LINEAR:
			if(x >= 1) return 1;
			else if(x < 0) return 0;
			else return x;
		case STANDARD_LOGISTIC:
			return 1 / (1 + pow(M_E,-x));
		case HYPERBOLIC_TANGENS:
			return (1 - exp(-x)) / (1 + exp(-x));
	}
	return 0;
}

double Neuron_old::operator()(const QList<double>& input) const{
	if(input.length() != weight.length()) return 0;
	double sum = bias;
	for(int i = 0; i < input.length(); i++)	sum += input[i] * weight[i];
	return transferFcn(sum);
}

double Neuron_old::operator()(const double input) const{
	if(weight.length() != 1) return 0;
	double sum = bias + weight.first()*input;
	return transferFcn(sum);
}

Neuron_old& Neuron_old::operator=(const Neuron_old& neuron){
	weight = neuron.weight;
	bias = neuron.bias;
	trFcn = neuron.trFcn;
	return *this;
}

}
