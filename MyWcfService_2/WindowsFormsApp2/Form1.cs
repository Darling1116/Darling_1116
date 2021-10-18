using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //浏览器获取url
            webBrowser1.Navigate(textBox1.Text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //获取中文繁体字
            string word = textBox2.Text;
            TraditionalSimplifiedWebService.TraditionalSimplifiedWebServiceSoapClient client = new TraditionalSimplifiedWebService.TraditionalSimplifiedWebServiceSoapClient();
            string toWotd = client.toTraditionalChinese(word);
            label4.Text = "转为繁体字为：" + toWotd;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //获取某一城市或地区的天气
            string city = textBox3.Text;
            WeatherWebService.WeatherWebService client1 = new WeatherWebService.WeatherWebService();
            string[] weather = client1.getWeatherbyCityName(city);
            label7.Text = "气温：" + weather[5];
            label8.Text = "概况：" + weather[6];
            label9.Text = "风向：" + weather[7];
            label10.Text = "风力：" + weather[8];
        }
    }
}
