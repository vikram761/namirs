#pragma once
#include <data_table.h>
#include <functional>
#include <memory>
#include <vector>

class SGD_REGRESSOR {
    float lr_, bias_;
    std::vector<float> weights_;
    std::shared_ptr<Table> data_table;
    uint max_iter;
    std::function<float(float)> activation;
    static float indentity(float x) { return x; };
  public:
    SGD_REGRESSOR(std::shared_ptr<Table> data_table);
    SGD_REGRESSOR(std::shared_ptr<Table> data_table, uint max_iter);
    SGD_REGRESSOR(std::shared_ptr<Table> data_table, uint max_iter, float learning_rate);
    void fit();
    float predict(std::vector<float> input_data);
    void set_activation(std::function<float(float)> activation);
    float bias();
    std::vector<float> weights();
};
