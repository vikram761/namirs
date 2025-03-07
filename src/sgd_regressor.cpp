#include "sgd_regressor.h"
#include "data_table.h"
#include <functional>
#include <iostream>
#include <memory>

SGD_REGRESSOR::SGD_REGRESSOR(std::shared_ptr<Table> data_table)
  : data_table(data_table), lr_(0.001), bias_(0.0f), max_iter(100000){
  this->weights_.resize(data_table->cols() - 1, 1);
  this->activation = indentity;
};

SGD_REGRESSOR::SGD_REGRESSOR(std::shared_ptr<Table> data_table, uint max_iter) 
  : SGD_REGRESSOR(data_table){
  this->max_iter = max_iter;
};

SGD_REGRESSOR::SGD_REGRESSOR(std::shared_ptr<Table> data_table, uint max_iter, float learning_rate) 
  : SGD_REGRESSOR(data_table, max_iter) {
  this->lr_ = learning_rate;
};

void SGD_REGRESSOR::fit() {
 
  for(int i=0; i < max_iter; i++){
    std::pair<std::vector<float> , float> data_point = data_table->sample_random_point();
    std::vector<float> input_data = data_point.first;

    float actual = data_point.second;
    float prediction = predict(input_data);
    float error = (actual - prediction);
    
    bias_ = bias_ + lr_ * (error);
    for(int j = 0; j < input_data.size(); j++) 
      weights_[j] = weights_[j] + lr_ * (error) * input_data[j];
  }

};

float SGD_REGRESSOR::predict(std::vector<float> input_data){
  if(input_data.size() != weights_.size()){
    std::cerr << "Input size does match" << std::endl;
    exit(1);
  }

  float prediction = bias_;
  for(size_t i =0;i < weights_.size(); i++) 
    prediction += weights_[i] * input_data[i];

  return activation(prediction);
};

void SGD_REGRESSOR::set_activation(std::function<float(float)> activation) {
  this->activation = activation;
};

std::vector<float> SGD_REGRESSOR::weights() { return weights_ ; };
float SGD_REGRESSOR::bias() { return bias_; };
