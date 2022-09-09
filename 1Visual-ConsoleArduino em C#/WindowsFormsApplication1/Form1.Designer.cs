namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.buttonEnvia = new System.Windows.Forms.Button();
            this.listBoxDados = new System.Windows.Forms.ListBox();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.textBoxEnvia = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "label1";
            // 
            // timer1
            // 
            this.timer1.Interval = 200;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // buttonEnvia
            // 
            this.buttonEnvia.Location = new System.Drawing.Point(48, 48);
            this.buttonEnvia.Name = "buttonEnvia";
            this.buttonEnvia.Size = new System.Drawing.Size(75, 23);
            this.buttonEnvia.TabIndex = 1;
            this.buttonEnvia.Text = "Enviar";
            this.buttonEnvia.UseVisualStyleBackColor = true;
            this.buttonEnvia.Click += new System.EventHandler(this.buttonEnvia_Click);
            // 
            // listBoxDados
            // 
            this.listBoxDados.FormattingEnabled = true;
            this.listBoxDados.Location = new System.Drawing.Point(48, 77);
            this.listBoxDados.Name = "listBoxDados";
            this.listBoxDados.Size = new System.Drawing.Size(397, 173);
            this.listBoxDados.TabIndex = 2;
            // 
            // textBoxEnvia
            // 
            this.textBoxEnvia.Location = new System.Drawing.Point(145, 51);
            this.textBoxEnvia.Name = "textBoxEnvia";
            this.textBoxEnvia.Size = new System.Drawing.Size(300, 20);
            this.textBoxEnvia.TabIndex = 3;
            this.textBoxEnvia.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxEnvia_KeyPress);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(592, 295);
            this.Controls.Add(this.textBoxEnvia);
            this.Controls.Add(this.listBoxDados);
            this.Controls.Add(this.buttonEnvia);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button buttonEnvia;
        private System.Windows.Forms.ListBox listBoxDados;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.TextBox textBoxEnvia;
    }
}

