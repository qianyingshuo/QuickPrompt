#include "ApplicationSetting.h"
namespace QP {

ApplicationSetting* ApplicationSetting::p=nullptr;

ApplicationSetting::ApplicationSetting()
{

}

ApplicationSetting *ApplicationSetting::getInstance()
{
    if(nullptr == p)
    {
         p = new ApplicationSetting();
         return p;
    }
    else
    {
        return p;
    }

}

ApplicationSetting *ApplicationSetting::setBrowserPath(QString path)
{
    m_borwserPath = path;
    return this;
}

QString ApplicationSetting::getBrowserPath()
{
    return m_borwserPath;
}
}
