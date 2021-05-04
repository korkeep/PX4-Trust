#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void moduleSelected(int moduleIndex);
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP