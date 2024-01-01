//Создать и описать классы. Для каждого класса (Н, МН, кН, мН, мкН) выполнить преобразование классов ко всем остальным.

#include <iostream>

using namespace std;

class MegaNewton;
class KiloNewton;
class MilliNewton;
class MicroNewton;

class Newton
{
public:
    Newton(float value)
    {
        this->value = value;
    }

    operator MegaNewton() const;
    operator KiloNewton() const;
    operator MilliNewton() const;
    operator MicroNewton() const;

    void PrintValue()
    {
        cout << this->value;
    }
private:
    float value;
};


class MegaNewton
{
public:
    MegaNewton(float value)
    {
        this->value = value;
    }

    operator Newton() const;
    operator KiloNewton() const;
    operator MilliNewton() const;
    operator MicroNewton() const;

    void PrintValue()
    {
        cout << this->value;
    }
private:
    float value;
};

class KiloNewton
{
public:
    KiloNewton(float value)
    {
        this->value = value;
    }

    operator Newton() const;
    operator MegaNewton() const;
    operator MilliNewton() const;
    operator MicroNewton() const;

    void PrintValue()
    {
        cout << this->value;
    }
private:
    float value;
};

class MilliNewton
{
public:
    MilliNewton(float value)
    {
        this->value = value;
    }

    operator Newton() const;
    operator MegaNewton() const;
    operator KiloNewton() const;
    operator MicroNewton() const;

    void PrintValue()
    {
        cout << this->value;
    }
private:
    float value;
};

class MicroNewton
{
public:
    MicroNewton(float value)
    {
        this->value = value;
    }

    operator Newton() const;
    operator MegaNewton() const;
    operator KiloNewton() const;
    operator MilliNewton() const;

    void PrintValue()
    {
        cout << this->value;
    }
private:
    float value;
};

//Newton:
Newton::operator MegaNewton() const
{
    return MegaNewton{ value / 1000000 };
}
Newton::operator KiloNewton() const
{
    return KiloNewton{ value / 1000 };
}
Newton::operator MilliNewton() const
{
    return MilliNewton{ value * 1000 };
}
Newton::operator MicroNewton() const
{
    return MicroNewton{ value * 1000000 };
}

//MegaNewton:
MegaNewton::operator Newton() const
{
    return Newton{ value * 1000000 };
}
MegaNewton::operator KiloNewton() const
{
    return KiloNewton{ value * 1000 };
}
MegaNewton::operator MilliNewton() const
{
    return MilliNewton{ value * 1000000000 };
}
MegaNewton::operator MicroNewton() const
{
    return MicroNewton{ value * 1000000000000 };
}

//KiloNewton:
KiloNewton::operator Newton() const
{
    return Newton{ value * 1000 };
}
KiloNewton::operator MegaNewton() const
{
    return MegaNewton{ value / 1000 };
}
KiloNewton::operator MilliNewton() const
{
    return MilliNewton{ value * 1000000 };
}
KiloNewton::operator MicroNewton() const
{
    return MicroNewton{ value * 1000000000 };
}

//MilliNewton:
MilliNewton::operator Newton() const
{
    return Newton{ value / 1000 };
}
MilliNewton::operator MegaNewton() const
{
    return MegaNewton{ value / 1000000000 };
}
MilliNewton::operator KiloNewton() const
{
    return KiloNewton{ value / 1000000 };
}
MilliNewton::operator MicroNewton() const
{
    return MicroNewton{ value * 1000 };
}

//MicroNewton:
MicroNewton::operator Newton() const
{
    return Newton{ value / 1000000 };
}
MicroNewton::operator MegaNewton() const
{
    return MegaNewton{ value / 1000000000000 };
}
MicroNewton::operator KiloNewton() const
{
    return KiloNewton{ value / 1000000000 };
}
MicroNewton::operator MilliNewton() const
{
    return MilliNewton{ value / 1000 };
}




int main()
{
    float inputValue;
    cout << "Please, enter the power: "; cin >> inputValue;
    Newton power{ inputValue };
    cout << "MN: ";
    MegaNewton a{ power };
    a.PrintValue();
    cout << "\nkN: ";
    KiloNewton b{ a };
    b.PrintValue();
    cout << "\nmN: ";
    MilliNewton c{ b };
    c.PrintValue();
    cout << "\nmcN: ";
    MicroNewton d{ c };
    d.PrintValue();
}