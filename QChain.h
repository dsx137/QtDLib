#pragma once

template<typename T>
class QChain {
private:
    T* p;
    T& d;
    bool rightPointer = false;
    bool rightValue = false;
public:
    QChain(T*& p) : d(d), p(p) {}//对现有指针引用
    QChain(T*&& p) : d(d), p(p) { rightPointer = true; }//new 一个指针（危险）
    QChain(T& d) : d(d), p(&d) {}//对左值变量引用
    QChain(T&& d) : d(d), p(&d) { rightValue = true; }//对右值变量引用
    ~QChain() { assert(!(rightPointer || rightValue)); };
    T* get() { rightPointer = false;return p; };
    T& data() { rightValue = false;return d; };
    QChain* operator->() { return this; };

    QChain(const QChain&) = delete; // 禁用拷贝构造函数
    QChain& operator=(const QChain&) = delete; // 禁用拷贝赋值运算符

    //Common
    template<typename T1>
    QChain* addChild(T1* child) { child->setParent(p);return this; };
    template<typename T1>
    QChain* setParent(T1* parent) { p->setParent(parent);return this; };
    template<typename T1>
    QChain* append(const T1& unit) { p->append(unit);return this; };

    //Widget
    template<typename T1>
    QChain* setLayout(T1* layout) { p->setLayout(layout);return this; };
    template<typename T1>
    QChain* setText(const T1& text) { p->setText(text);return this; };
    template<typename T1>
    QChain* addWidget(T1* widget) { p->addWidget(widget);return this; };
    template<typename T1>
    QChain* addLayout(T1* layout) { p->addLayout(layout);return this; };
    template<typename T1>
    QChain* setStyleSheet(const T1& styleSheet) { p->setStyleSheet(styleSheet);return this; };
    template<typename T1>
    QChain* setFont(const T1& font) { p->setFont(font);return this; };
    template<typename T1>
    QChain* setAlignment(const T1& alignment) { p->setAlignment(alignment);return this; };
    template<typename T1>
    QChain* setValidator(const T1& validator) { p->setValidator(validator);return this; };

    QChain* setFixedSize(int w, int h) { p->setFixedSize(w, h);return this; };
    QChain* setFixedHeight(int h) { p->setFixedHeight(h);return this; };
    QChain* setFixedWidth(int w) { p->setFixedWidth(w);return this; };
    QChain* setReadOnly(bool ro) { p->setReadOnly(ro);return this; };
    QChain* setSpacing(int spacing) { p->setSpacing(spacing);return this; };
    QChain* setContentMargins(int left, int top, int right, int bottom) { p->setContentMargins(left, top, right, bottom);return this; };

    //network
    template<typename T1>
    QChain* setUrl(const T1& url) { p->setUrl(url);return this; };
    template<typename T1>
    QChain* setBoundary(const T1& boundary) { p->setBoundary(boundary);return this; };
    template<typename T1>
    QChain* setBody(const T1& body) { p->setBody(body);return this; };
    template<typename T1, typename T2>
    QChain* setRawHeader(const T1& headerName, const T2& headerValue) { p->setRawHeader(headerName, headerValue);return this; };
    template<typename T1, typename T2>
    QChain* setHeader(T1 header, const T2& value) { p->setHeader(header, value);return this; };
};