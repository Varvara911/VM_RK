#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <limits>


class cubic_spline
{
private:
    // Структура, описывающая сплайн на каждом сегменте сетки
    struct spline_tuple
    {
        double a, b, c, d, x;
    };
 
    spline_tuple *splines; // Сплайн
    size_t n; // Количество узлов сетки
 
    void free_mem(); // Освобождение памяти
 
public:
    cubic_spline(); //конструктор
    ~cubic_spline(); //деструктор
 
    // Построение сплайна
    // x - узлы сетки, должны быть упорядочены по возрастанию, кратные узлы запрещены
    // y - значения функции в узлах сетки
    // n - количество узлов сетки
    void build_spline(const double *x, const double *y, size_t n);
 
    // Вычисление значения интерполированной функции в произвольной точке
    double f(double x) const;
};
 
cubic_spline::cubic_spline() : splines(NULL)
{
 
}
 
cubic_spline::~cubic_spline()
{
    free_mem();
}
 
void cubic_spline::build_spline(const double *x, const double *y, size_t n)
{
    free_mem();
 
    this->n = n;
 
    // Инициализация массива сплайнов
    splines = new spline_tuple[n];
    for (size_t i = 0; i < n; ++i)
    {
        splines[i].x = x[i];
        splines[i].a = y[i];
    }
    splines[0].c = splines[n - 1].c = 0.;
 
    // Решение СЛАУ относительно коэффициентов сплайнов c[i] методом прогонки для трехдиагональных матриц
    // Вычисление прогоночных коэффициентов - прямой ход метода прогонки
    double *alpha = new double[n - 1];
    double *beta = new double[n - 1];
    alpha[0] = beta[0] = 0.;
    for (size_t i = 1; i < n - 1; ++i)
    {
        double h_i = x[i] - x[i - 1], h_i1 = x[i + 1] - x[i];
        double A = h_i;
        double C = 2. * (h_i + h_i1);
        double B = h_i1;
        double F = 6. * ((y[i + 1] - y[i]) / h_i1 - (y[i] - y[i - 1]) / h_i);
        double z = (A * alpha[i - 1] + C);
        alpha[i] = -B / z;
        beta[i] = (F - A * beta[i - 1]) / z;
    }
 
    // Нахождение решения - обратный ход метода прогонки
    for (size_t i = n - 2; i > 0; --i)
        splines[i].c = alpha[i] * splines[i + 1].c + beta[i];
 
    // Освобождение памяти, занимаемой прогоночными коэффициентами
    delete[] beta;
    delete[] alpha;
 
    // По известным коэффициентам c[i] находим значения b[i] и d[i]
    for (size_t i = n - 1; i > 0; --i)
    {
        double h_i = x[i] - x[i - 1];
        splines[i].d = (splines[i].c - splines[i - 1].c) / h_i;
        splines[i].b = h_i * (2. * splines[i].c + splines[i - 1].c) / 6. + (y[i] - y[i - 1]) / h_i;
    }
}
 
double cubic_spline::f(double x) const
{
    if (!splines)
        return std::numeric_limits<double>::quiet_NaN(); // Если сплайны ещё не построены - возвращаем NaN
 
    spline_tuple *s;
    if (x <= splines[0].x) // Если x меньше точки сетки x[0] - пользуемся первым эл-тов массива
        s = splines + 1;
    else if (x >= splines[n - 1].x) // Если x больше точки сетки x[n - 1] - пользуемся последним эл-том массива
        s = splines + n - 1;
    else // Иначе x лежит между граничными точками сетки - производим бинарный поиск нужного эл-та массива
    {
        size_t i = 0, j = n - 1;
        while (i + 1 < j)
        {
            std::size_t k = i + (j - i) / 2;
            if (x <= splines[k].x)
                j = k;
            else
                i = k;
        }
        s = splines + j;
    }
 
    double dx = (x - s->x);
	// Вычисляем значение сплайна в заданной точке по схеме Горнера
	//(в принципе, "умный" компилятор применил бы схему Горнера сам, но ведь не все так умны, как кажутся)
    return s->a + (s->b + (s->c / 2. + s->d * dx / 6.) * dx) * dx;
}

void cubic_spline::free_mem()
{
    if (splines)
    {
        delete[] splines;
        splines = NULL;
    }
}

