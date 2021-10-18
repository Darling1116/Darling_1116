using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace MyWcfService_2
{
    // 注意: 使用“重构”菜单上的“重命名”命令，可以同时更改代码、svc 和配置文件中的类名“Service1”。
    // 注意: 为了启动 WCF 测试客户端以测试此服务，请在解决方案资源管理器中选择 Service1.svc 或 Service1.svc.cs，然后开始调试。
    public class Service1 : IService1
    {   
        //将摄氏温度转换为华氏温度
        public double C2f(double c)
        {
            return (32 + 1.8 * c);
        }

        //将华氏温度转换为摄氏温度
        public double F2c(double f)
        {
            return ((f - 32) / 1.8);
        }

    }
}
