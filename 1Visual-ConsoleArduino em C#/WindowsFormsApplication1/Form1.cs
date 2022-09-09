using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private int i;
        private String atual;
        byte[] valor;
        private System.IO.Ports.SerialPort porta;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            /*String[] texto = new String[50];
            texto = System.IO.Ports.SerialPort.GetPortNames();
            label1.Text = texto[0];//COM 4*/
            
            porta = new System.IO.Ports.SerialPort("COM3", 9600);
            try
            {
                porta.Open();
                label1.Text = "Conectado";
                i = 0;
                valor = new Byte[]{0,1};
                timer1.Start();
            }
            catch (Exception)
            {
                label1.Text = "Não Conectado";

            }
            
            
            

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            
            /*porta.Write(i.ToString());
            label1.Text = "i: "+i.ToString()+" Valor lido: "+porta.ReadExisting();
            i++;*/
            atual = porta.ReadExisting();
            if (atual != "")
            listBoxDados.Items.Add(atual);


        }

        private void buttonEnvia_Click(object sender, EventArgs e)
        {
            porta.Write(textBoxEnvia.Text);
        }

        private void textBoxEnvia_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((Keys)e.KeyChar == Keys.Enter) porta.Write(textBoxEnvia.Text);
        }
    }
}
