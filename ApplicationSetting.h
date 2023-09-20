#ifndef APPLICATIONSETTING_H
#define APPLICATIONSETTING_H

#include <QString>
namespace QP {


class ApplicationSetting
{
public:
    static ApplicationSetting *getInstance();

    ApplicationSetting *setBrowserPath(QString path);

    QString getBrowserPath();
private:
    static ApplicationSetting* p;
    ApplicationSetting();
    ~ApplicationSetting();
    ApplicationSetting(const ApplicationSetting &) = delete;
    const ApplicationSetting &operator=(const ApplicationSetting &) = delete;
    QString m_borwserPath{""};
};
}
#endif // APPLICATIONSETTING_H
