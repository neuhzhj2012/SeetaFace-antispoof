
struct pybv_bv_SF6ANTISPOOF_t
{
    PyObject_HEAD
    Ptr<bv::SF6ANTISPOOF> v;
};

static PyTypeObject pybv_bv_SF6ANTISPOOF_Type =
{
    CV_PYTHON_TYPE_HEAD_INIT()
    MODULESTR".bv_SF6ANTISPOOF",
    sizeof(pybv_bv_SF6ANTISPOOF_t),
};

static void pybv_bv_SF6ANTISPOOF_dealloc(PyObject* self)
{
    ((pybv_bv_SF6ANTISPOOF_t*)self)->v.release();
    PyObject_Del(self);
}

template<> PyObject* pybv_from(const Ptr<bv::SF6ANTISPOOF>& r)
{
    pybv_bv_SF6ANTISPOOF_t *m = PyObject_NEW(pybv_bv_SF6ANTISPOOF_t, &pybv_bv_SF6ANTISPOOF_Type);
    new (&(m->v)) Ptr<bv::SF6ANTISPOOF>(); // init Ptr with placement new
    m->v = r;
    return (PyObject*)m;
}

template<> bool pybv_to(PyObject* src, Ptr<bv::SF6ANTISPOOF>& dst, const char* name)
{
    if( src == NULL || src == Py_None )
        return true;
    if(!PyObject_TypeCheck(src, &pybv_bv_SF6ANTISPOOF_Type))
    {
        failmsg("Expected bv::SF6ANTISPOOF for argument '%s'", name);
        return false;
    }
    dst = ((pybv_bv_SF6ANTISPOOF_t*)src)->v.dynamicCast<bv::SF6ANTISPOOF>();
    return true;
}


static PyObject* pybv_bv_SF6ANTISPOOF_repr(PyObject* self)
{
    char str[1000];
    sprintf(str, "<bv_SF6ANTISPOOF %p>", self);
    return PyString_FromString(str);
}



static PyGetSetDef pybv_bv_SF6ANTISPOOF_getseters[] =
{
    {NULL}  /* Sentinel */
};

static int pybv_bv_bv_SF6ANTISPOOF_SF6ANTISPOOF(pybv_bv_SF6ANTISPOOF_t* self, PyObject* args, PyObject* kw)
{
    using namespace bv;

    float clarity=0.3;
    float reality=0.01;

    const char* keywords[] = { "clarity", "reality", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "|ff:SF6ANTISPOOF", (char**)keywords, &clarity, &reality) )
    {
        new (&(self->v)) Ptr<bv::SF6ANTISPOOF>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new bv::SF6ANTISPOOF(clarity, reality)));
        return 0;
    }

    return -1;
}

static PyObject* pybv_bv_bv_SF6ANTISPOOF_predict(PyObject* self, PyObject* args, PyObject* kw)
{
    using namespace bv;

    bv::SF6ANTISPOOF* _self_ = NULL;
    if(PyObject_TypeCheck(self, &pybv_bv_SF6ANTISPOOF_Type))
        _self_ = ((pybv_bv_SF6ANTISPOOF_t*)self)->v.get();
    if (_self_ == NULL)
        return failmsgp("Incorrect type of self (must be 'bv_SF6ANTISPOOF' or its derivative)");
    {
    PyObject* pyobj_im = NULL;
    Mat im;
    bool retval;

    const char* keywords[] = { "im", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:bv_SF6ANTISPOOF.predict", (char**)keywords, &pyobj_im) &&
        pybv_to(pyobj_im, im, ArgInfo("im", 0)) )
    {
        ERRWRAP2(retval = _self_->predict(im));
        return pybv_from(retval);
    }
    }
    PyErr_Clear();

    {
    PyObject* pyobj_im = NULL;
    Mat im;
    bool retval;

    const char* keywords[] = { "im", NULL };
    if( PyArg_ParseTupleAndKeywords(args, kw, "O:bv_SF6ANTISPOOF.predict", (char**)keywords, &pyobj_im) &&
        pybv_to(pyobj_im, im, ArgInfo("im", 0)) )
    {
        ERRWRAP2(retval = _self_->predict(im));
        return pybv_from(retval);
    }
    }

    return NULL;
}



static PyMethodDef pybv_bv_SF6ANTISPOOF_methods[] =
{
    {"predict", (PyCFunction)pybv_bv_bv_SF6ANTISPOOF_predict, METH_VARARGS | METH_KEYWORDS, "predict(im) -> retval\n."},

    {NULL,          NULL}
};

static void pybv_bv_SF6ANTISPOOF_specials(void)
{
    pybv_bv_SF6ANTISPOOF_Type.tp_base = NULL;
    pybv_bv_SF6ANTISPOOF_Type.tp_dealloc = pybv_bv_SF6ANTISPOOF_dealloc;
    pybv_bv_SF6ANTISPOOF_Type.tp_repr = pybv_bv_SF6ANTISPOOF_repr;
    pybv_bv_SF6ANTISPOOF_Type.tp_getset = pybv_bv_SF6ANTISPOOF_getseters;
    pybv_bv_SF6ANTISPOOF_Type.tp_init = (initproc)pybv_bv_bv_SF6ANTISPOOF_SF6ANTISPOOF;
    pybv_bv_SF6ANTISPOOF_Type.tp_methods = pybv_bv_SF6ANTISPOOF_methods;
}
