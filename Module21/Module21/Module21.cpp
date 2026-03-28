#include <iostream>
#include <memory>
class iDeliveryStrategy {
public:
    virtual float calculateCost(float weight, float distance) const = 0;
    ~iDeliveryStrategy() = default;
};

class GroundDelivery : public iDeliveryStrategy {
public:
    float calculateCost(float weight, float distance) const override{
        float rate = 0.5f;
        return distance * rate;
    }
};

class AirDelivery : public iDeliveryStrategy {
public:
    float calculateCost(float weight, float distance) const override {
        float rate = 1.2f;
        return distance * rate + weight * 2.0f;
    }
};

class ExpressDelivery : public iDeliveryStrategy {
public:
    float calculateCost(float weight, float distance) const override {
        float rate = 2.0f;
        float urgency = 10.0f;
        return distance * rate + weight * 3.0f + urgency;
    }
};

class DeliveryContext {
public:
    DeliveryContext(std::unique_ptr<iDeliveryStrategy> strategy)
        : _strategy(std::move(strategy)) {
    }
    void setStrategy(std::unique_ptr<iDeliveryStrategy> other) {
        _strategy = std::move(other);
    }
    float calculate(float weight, float distance) const {
        return _strategy->calculateCost(weight, distance);

    }

private:
    std::unique_ptr<iDeliveryStrategy> _strategy;
};

int main()
{
    std::cout << "Hello World!\n";
    float weight = 5.0f;
    float distance = 20.0f;

    DeliveryContext context(std::make_unique<GroundDelivery>());
    std::cout << "ground: " << context.calculate(weight, distance) << "\n";
    context.setStrategy(std::make_unique<AirDelivery>());
    std::cout << "air: " << context.calculate(weight, distance) << "\n";
    context.setStrategy(std::make_unique<ExpressDelivery>());
    std::cout << "express: " << context.calculate(weight, distance) << "\n";

}
