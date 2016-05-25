#pragma once

template <typename T>
/*!
 * \brief Умный указатель SharedPointer.
 */
class SharedPointer
{
public:
    SharedPointer(T* object = nullptr) : pointer(new Pointer(object)){}
    /*!
     * \brief Конструктор копирования
     * \param pointerToCopy Указатель, который мы копируем
     */
    SharedPointer(SharedPointer<T> &pointerToCopy)
    {
        pointer = pointerToCopy.pointer;
        pointer->count++;
    }
    ~SharedPointer()
    {
        deletePointer();
    }
    T& operator * ()
    {
        return *pointer->object;
    }
    /*!
     * \brief Оператор присваивания
     * \param newPointer Новый указатель, который нам надо присвоить.
     */
    void operator = (const SharedPointer<T> &newPointer)
    {
        deletePointer();
        pointer = newPointer.pointer;
        pointer->count++;
    }
    /*!
     * \brief Получить счётчик
     * \return Целое число - на сколько объектов ссылается указатель.
     */
    int getCount() const
    {
        return pointer->count;
    }
private:
    /*!
     * \brief Вспомогательный класс Pointer
     */
    class Pointer
    {
    public:
        Pointer(T* pointer):
            object(pointer){}
        ~Pointer()
        {
            delete object;
        }
        T* object; ///< Сам указатель на объект типа T.
        int count = 1; ///< Счётчик ссылок на выделенную память.
    };
    Pointer *pointer;
    void deletePointer()
    {
        pointer->count--;
        if (pointer->count == 0)
            delete pointer;
    }
};
