using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double c = Convert.ToDouble(textBox1.Text);
            ServiceReference1.Service1Client client = new ServiceReference1.Service1Client();
            label3.Text = "华氏温度为：" + client.C2f(c);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double f = Convert.ToDouble(textBox2.Text);
            ServiceReference1.Service1Client client = new ServiceReference1.Service1Client();
            label5.Text = "摄氏温度为：" + client.F2c(f);
        }
    }
}
