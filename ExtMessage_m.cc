//
// Generated file, do not edit! Created by nedtool 4.6 from ExtMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ExtMessage_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(ExtMessage);

ExtMessage::ExtMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->mask_var = 0;
    this->hop_var = 0;
}

ExtMessage::ExtMessage(const ExtMessage& other) : ::cMessage(other)
{
    copy(other);
}

ExtMessage::~ExtMessage()
{
}

ExtMessage& ExtMessage::operator=(const ExtMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ExtMessage::copy(const ExtMessage& other)
{
    this->srcAddress_var = other.srcAddress_var;
    this->dstAddress_var = other.dstAddress_var;
    this->mask_var = other.mask_var;
    this->hop_var = other.hop_var;
}

void ExtMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->srcAddress_var);
    doPacking(b,this->dstAddress_var);
    doPacking(b,this->mask_var);
    doPacking(b,this->hop_var);
}

void ExtMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->srcAddress_var);
    doUnpacking(b,this->dstAddress_var);
    doUnpacking(b,this->mask_var);
    doUnpacking(b,this->hop_var);
}

IPAddress& ExtMessage::getSrcAddress()
{
    return srcAddress_var;
}

void ExtMessage::setSrcAddress(const IPAddress& srcAddress)
{
    this->srcAddress_var = srcAddress;
}

IPAddress& ExtMessage::getDstAddress()
{
    return dstAddress_var;
}

void ExtMessage::setDstAddress(const IPAddress& dstAddress)
{
    this->dstAddress_var = dstAddress;
}

int ExtMessage::getMask() const
{
    return mask_var;
}

void ExtMessage::setMask(int mask)
{
    this->mask_var = mask;
}

int ExtMessage::getHop() const
{
    return hop_var;
}

void ExtMessage::setHop(int hop)
{
    this->hop_var = hop;
}

class ExtMessageDescriptor : public cClassDescriptor
{
  public:
    ExtMessageDescriptor();
    virtual ~ExtMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ExtMessageDescriptor);

ExtMessageDescriptor::ExtMessageDescriptor() : cClassDescriptor("ExtMessage", "cMessage")
{
}

ExtMessageDescriptor::~ExtMessageDescriptor()
{
}

bool ExtMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ExtMessage *>(obj)!=NULL;
}

const char *ExtMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ExtMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int ExtMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *ExtMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcAddress",
        "dstAddress",
        "mask",
        "hop",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int ExtMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstAddress")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "mask")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ExtMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPAddress",
        "IPAddress",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *ExtMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ExtMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ExtMessage *pp = (ExtMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ExtMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ExtMessage *pp = (ExtMessage *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDstAddress(); return out.str();}
        case 2: return long2string(pp->getMask());
        case 3: return long2string(pp->getHop());
        default: return "";
    }
}

bool ExtMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ExtMessage *pp = (ExtMessage *)object; (void)pp;
    switch (field) {
        case 2: pp->setMask(string2long(value)); return true;
        case 3: pp->setHop(string2long(value)); return true;
        default: return false;
    }
}

const char *ExtMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return opp_typename(typeid(IPAddress));
        case 1: return opp_typename(typeid(IPAddress));
        default: return NULL;
    };
}

void *ExtMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ExtMessage *pp = (ExtMessage *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcAddress()); break;
        case 1: return (void *)(&pp->getDstAddress()); break;
        default: return NULL;
    }
}


