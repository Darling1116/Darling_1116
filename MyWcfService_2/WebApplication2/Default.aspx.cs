using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication2
{
    public partial class _Default : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void button1_Click(object sender, EventArgs e)
        {
            //获取摄氏温度
            double c = Convert.ToDouble(textBox1.Text);
            ServiceReference2.Service1Client client = new ServiceReference2.Service1Client();
            label3.Text = "华氏温度为：" + client.C2f(c).ToString();
        }


        private void button2_Click(object sender, EventArgs e)
        {
            //获取华氏温度
            double f = Convert.ToDouble(textBox2.Text);
            ServiceReference2.Service1Client client = new ServiceReference2.Service1Client();
            label5.Text = "摄氏温度为：" + client.F2c(f).ToString();
        }
    }
}