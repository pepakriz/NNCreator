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

#include "Neuron.h"

namespace NeuronNetwork{
/*
Neuron::Neuron(void) : bias(0), trFcn(HYPERBOLIC_TANGENS){
	weight = Array<double>(1, 0);
}

Neuron::Neuron(const Neuron& neuron) : bias(0){
	trFcn = neuron.trFcn;
	weight = Array<double>(neuron.weight);
}

Neuron::Neuron(const unsigned int inputCount) : bias(0), trFcn(HYPERBOLIC_TANGENS){
	weight = Array<double>(inputCount, 0);
}

Neuron::~Neuron(void){}

void Neuron::setBias(const double bias){
	this->bias = bias;
}

double Neuron::getBias(void) const{
	return bias;
}

Array<double> Neuron::getWeight() const{
	return weight;
}

void Neuron::setWeight(const Array<double>& weight){
	this->weight = weight;
}

void Neuron::setTransferFunction(const TransferFunction transferFunction){
	this->trFcn = transferFunction;
}

TransferFunction Neuron::getTransferFunction() const{
	return trFcn;
}

double Neuron::operator[](const unsigned int index) const{
	return weight[index];
}

double Neuron::operator()(const Array<double>& input){
	//if(input.getLength() != weight.getLength()) return 0;
	double sum = bias;
	for(unsigned int i = 0; i < input.length(); i++){
		sum += input[i] * weight[i];
	}
	switch(trFcn){
		case NOT_LINEAR:
			return sum >= 1 ? 1 : 0;
		case SATURATED_LINEAR:
			if(sum >= 1) return 1;
			else if(sum < 0) return 0;
			else return sum;
		case STANDARD_LOGISTIC:
			return 1 / (1 + pow(M_E,-sum));
		case HYPERBOLIC_TANGENS:
			return (1 - pow(M_E,-sum)) / (1 + pow(M_E,-sum));
	}
}

Neuron& Neuron::operator=(Neuron& neuron){
	weight = neuron.weight;
	bias = neuron.bias;
	trFcn = neuron.trFcn;
	return *this;
}

QTextStream& operator<<(QTextStream& ostr, const Neuron& neuron){
	ostr << QString("Neuron:\n");
	ostr << QString("weights = ") << neuron.weight << QString("\n");
	ostr << QString("bias = ") << neuron.bias << QString("\n");
	ostr << QString("transferFunction = ") << neuron.trFcn;
	return ostr;
}

QTextStream& operator>>(QTextStream& istr, Neuron& neuron){

}

Neuron Neuron::valueOf(QString text){
	QStringList line = text.replace(" ", "").split("\n");

	if(line[0] != QString("Neuron:")){
		throw Exception(ValueOfParseErrorBadKeyword, "\"" +line[0] + "\", expected: \"Neuron:\"");
	}

	Neuron neuron = Neuron();

	if(line[1].split("=")[0] != "weights"){
		throw Exception(ValueOfParseErrorBadKeyword, "\"" + line[1].split("=")[0] + "\", expected: \"weights\"");
	}else{
		QString wgs = line[1].split("=")[1];
		wgs = wgs.remove(0, 1);
		wgs = wgs.remove(wgs.length()-1, 1);

		QStringList wg = wgs.split(",");

		Array<double> weights = Array<double>(wg.length(), 0.0);
		for(int i = 0; i < wg.length(); i++){
			bool* ok = new bool;
			weights[i] = wg[i].toDouble(ok);
			if(!*ok){
				delete ok;
				throw Exception(ValueOfParseErrorIsntDouble, "\"" + wg[i] + "\"");
			}
			delete ok;
		}

		neuron.setWeight(weights);
	}

	if(line[2].split("=")[0] != "bias"){
		throw Exception(ValueOfParseErrorBadKeyword, "\"" + line[2].split("=")[0] + "\", expected: \"bias\"");
	}else{
		bool* ok = new bool;
		neuron.setBias(line[2].split("=")[1].toDouble(ok));
		if(!*ok){
			delete ok;
			throw Exception(ValueOfParseErrorIsntDouble, "\"" + line[2].split("=")[1] + "\"");
		}
		delete ok;
	}

	if(line[3].split("=")[0] != "transferFunction"){
		throw Exception(ValueOfParseErrorBadKeyword, "\"" + line[3].split("=")[0] + "\", expected: \"transferFunction\"");
	}else{
		bool* ok = new bool;
		int trFc = line[3].split("=")[1].toInt(ok);
		if(!*ok){
			delete ok;
			throw Exception(ValueOfParseErrorIsntInt, "\"" + line[3].split("=")[1] + "\"");
		}
		delete ok;

		if(trFc < 0 || trFc > 4){
			throw Exception(ValueOfParseErrorIsntTrFc, "\"" + line[3].split("=")[1] + "\"");
		}else{
			neuron.setTransferFunction((TransferFunction)trFc);
		}
	}

	return neuron;
}

QString Neuron::toString(){
	QString* device = new QString;
	QTextStream ostr(device);
	ostr << *this;
	QString a(*device);
	delete device;
	return a;
}
*/
}
