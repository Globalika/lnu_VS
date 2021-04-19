
namespace WinApp
{
    partial class WikiForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label8 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.article_title = new System.Windows.Forms.TextBox();
            this.article_genre = new System.Windows.Forms.TextBox();
            this.author_Id = new System.Windows.Forms.TextBox();
            this.article_Id = new System.Windows.Forms.TextBox();
            this.add_article = new System.Windows.Forms.Button();
            this.delete_article = new System.Windows.Forms.Button();
            this.author_table_button = new System.Windows.Forms.Button();
            this.refresh_button = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Location = new System.Drawing.Point(-2, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1010, 595);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.tabPage1.Controls.Add(this.panel1);
            this.tabPage1.Controls.Add(this.dataGridView1);
            this.tabPage1.Location = new System.Drawing.Point(4, 34);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1002, 557);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "WikiArticles";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.label8);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label7);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.article_title);
            this.panel1.Controls.Add(this.article_genre);
            this.panel1.Controls.Add(this.author_Id);
            this.panel1.Controls.Add(this.article_Id);
            this.panel1.Controls.Add(this.add_article);
            this.panel1.Controls.Add(this.delete_article);
            this.panel1.Controls.Add(this.author_table_button);
            this.panel1.Controls.Add(this.refresh_button);
            this.panel1.Location = new System.Drawing.Point(57, 20);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(892, 143);
            this.panel1.TabIndex = 4;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(440, 15);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(53, 25);
            this.label8.TabIndex = 25;
            this.label8.Text = "Title :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(610, 15);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 25);
            this.label3.TabIndex = 24;
            this.label3.Text = "Genre :";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(267, 15);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(97, 25);
            this.label7.TabIndex = 23;
            this.label7.Text = "Author Id :";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(166, 15);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(37, 25);
            this.label6.TabIndex = 22;
            this.label6.Text = "Id :";
            // 
            // article_title
            // 
            this.article_title.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.article_title.Location = new System.Drawing.Point(499, 12);
            this.article_title.Name = "article_title";
            this.article_title.Size = new System.Drawing.Size(95, 31);
            this.article_title.TabIndex = 20;
            // 
            // article_genre
            // 
            this.article_genre.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.article_genre.Location = new System.Drawing.Point(683, 12);
            this.article_genre.Name = "article_genre";
            this.article_genre.Size = new System.Drawing.Size(96, 31);
            this.article_genre.TabIndex = 19;
            // 
            // author_Id
            // 
            this.author_Id.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.author_Id.Location = new System.Drawing.Point(370, 12);
            this.author_Id.Name = "author_Id";
            this.author_Id.Size = new System.Drawing.Size(62, 31);
            this.author_Id.TabIndex = 18;
            // 
            // article_Id
            // 
            this.article_Id.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.article_Id.Location = new System.Drawing.Point(203, 12);
            this.article_Id.Name = "article_Id";
            this.article_Id.Size = new System.Drawing.Size(58, 31);
            this.article_Id.TabIndex = 17;
            // 
            // add_article
            // 
            this.add_article.BackColor = System.Drawing.Color.Red;
            this.add_article.Location = new System.Drawing.Point(40, 10);
            this.add_article.Name = "add_article";
            this.add_article.Size = new System.Drawing.Size(122, 34);
            this.add_article.TabIndex = 6;
            this.add_article.Text = "Add Article";
            this.add_article.UseVisualStyleBackColor = false;
            this.add_article.Click += new System.EventHandler(this.add_article_Click);
            // 
            // delete_article
            // 
            this.delete_article.BackColor = System.Drawing.Color.Red;
            this.delete_article.Location = new System.Drawing.Point(40, 50);
            this.delete_article.Name = "delete_article";
            this.delete_article.Size = new System.Drawing.Size(128, 34);
            this.delete_article.TabIndex = 5;
            this.delete_article.Text = "Delete Article";
            this.delete_article.UseVisualStyleBackColor = false;
            this.delete_article.Click += new System.EventHandler(this.delete_article_Click);
            // 
            // author_table_button
            // 
            this.author_table_button.BackColor = System.Drawing.Color.Red;
            this.author_table_button.Location = new System.Drawing.Point(508, 99);
            this.author_table_button.Name = "author_table_button";
            this.author_table_button.Size = new System.Drawing.Size(202, 34);
            this.author_table_button.TabIndex = 4;
            this.author_table_button.Text = "Open Author Table";
            this.author_table_button.UseVisualStyleBackColor = false;
            this.author_table_button.Click += new System.EventHandler(this.author_table_button_Click);
            // 
            // refresh_button
            // 
            this.refresh_button.BackColor = System.Drawing.Color.Red;
            this.refresh_button.Location = new System.Drawing.Point(753, 99);
            this.refresh_button.Name = "refresh_button";
            this.refresh_button.Size = new System.Drawing.Size(112, 34);
            this.refresh_button.TabIndex = 1;
            this.refresh_button.Text = "Refresh";
            this.refresh_button.UseVisualStyleBackColor = false;
            this.refresh_button.Click += new System.EventHandler(this.refresh_button_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.BackgroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(55, 181);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 62;
            this.dataGridView1.RowTemplate.Height = 33;
            this.dataGridView1.Size = new System.Drawing.Size(894, 368);
            this.dataGridView1.TabIndex = 0;
            // 
            // WikiForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.ClientSize = new System.Drawing.Size(1002, 595);
            this.Controls.Add(this.tabControl1);
            this.Name = "WikiForm";
            this.Text = "WikiApp";
            this.Load += new System.EventHandler(this.WikiForm_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button refresh_button;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button author_table_button;
        private System.Windows.Forms.Button add_article;
        private System.Windows.Forms.Button delete_article;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox article_title;
        private System.Windows.Forms.TextBox article_genre;
        private System.Windows.Forms.TextBox author_Id;
        private System.Windows.Forms.TextBox article_Id;
    }
}

