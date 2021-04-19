
namespace WinApp.AuthorsForms
{
    partial class AuthorTableForm
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
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.label11 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.author_name = new System.Windows.Forms.TextBox();
            this.author_Id = new System.Windows.Forms.TextBox();
            this.delete_author = new System.Windows.Forms.Button();
            this.add_author = new System.Windows.Forms.Button();
            this.refresh = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Location = new System.Drawing.Point(-2, -2);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(804, 458);
            this.tabControl1.TabIndex = 1;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.tabPage1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.tabPage1.Controls.Add(this.label11);
            this.tabPage1.Controls.Add(this.label6);
            this.tabPage1.Controls.Add(this.author_name);
            this.tabPage1.Controls.Add(this.author_Id);
            this.tabPage1.Controls.Add(this.delete_author);
            this.tabPage1.Controls.Add(this.add_author);
            this.tabPage1.Controls.Add(this.refresh);
            this.tabPage1.Controls.Add(this.dataGridView1);
            this.tabPage1.Location = new System.Drawing.Point(4, 34);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(796, 420);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "AuthorTable";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(309, 36);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(68, 25);
            this.label11.TabIndex = 27;
            this.label11.Text = "Name :";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(202, 35);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(37, 25);
            this.label6.TabIndex = 26;
            this.label6.Text = "Id :";
            // 
            // author_name
            // 
            this.author_name.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.author_name.Location = new System.Drawing.Point(383, 33);
            this.author_name.Name = "author_name";
            this.author_name.Size = new System.Drawing.Size(76, 31);
            this.author_name.TabIndex = 25;
            // 
            // author_Id
            // 
            this.author_Id.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.author_Id.Location = new System.Drawing.Point(245, 33);
            this.author_Id.Name = "author_Id";
            this.author_Id.Size = new System.Drawing.Size(58, 31);
            this.author_Id.TabIndex = 24;
            // 
            // delete_author
            // 
            this.delete_author.BackColor = System.Drawing.Color.Red;
            this.delete_author.Location = new System.Drawing.Point(562, 84);
            this.delete_author.Name = "delete_author";
            this.delete_author.Size = new System.Drawing.Size(133, 34);
            this.delete_author.TabIndex = 3;
            this.delete_author.Text = "Delete Author";
            this.delete_author.UseVisualStyleBackColor = false;
            this.delete_author.Click += new System.EventHandler(this.delete_author_Click);
            // 
            // add_author
            // 
            this.add_author.BackColor = System.Drawing.Color.Red;
            this.add_author.Location = new System.Drawing.Point(562, 30);
            this.add_author.Name = "add_author";
            this.add_author.Size = new System.Drawing.Size(133, 34);
            this.add_author.TabIndex = 2;
            this.add_author.Text = "Add Author";
            this.add_author.UseVisualStyleBackColor = false;
            this.add_author.Click += new System.EventHandler(this.add_author_Click);
            // 
            // refresh
            // 
            this.refresh.BackColor = System.Drawing.Color.Red;
            this.refresh.Location = new System.Drawing.Point(562, 358);
            this.refresh.Name = "refresh";
            this.refresh.Size = new System.Drawing.Size(112, 34);
            this.refresh.TabIndex = 1;
            this.refresh.Text = "Refresh";
            this.refresh.UseVisualStyleBackColor = false;
            this.refresh.Click += new System.EventHandler(this.refresh_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.BackgroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(42, 93);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 62;
            this.dataGridView1.RowTemplate.Height = 33;
            this.dataGridView1.Size = new System.Drawing.Size(434, 299);
            this.dataGridView1.TabIndex = 0;
            // 
            // AuthorTableForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tabControl1);
            this.Name = "AuthorTableForm";
            this.Text = "AuthorApp";
            this.Load += new System.EventHandler(this.AuthorTable_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button delete_author;
        private System.Windows.Forms.Button add_author;
        private System.Windows.Forms.Button refresh;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox author_name;
        private System.Windows.Forms.TextBox author_Id;
    }
}