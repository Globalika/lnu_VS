using MyWikipediaTask3.Entities;
using MyWikipediaTask3.Repository.Impl;
using System;
using System.Windows.Forms;

namespace WinApp.AuthorsForms
{
    public partial class AuthorTableForm : Form
    {
        BaseRepository<Author> authorRepos;
        ArticleRepository articleRepos;
        public AuthorTableForm(BaseRepository<Author> authorRepos, ArticleRepository articleRepos)
        {
            this.authorRepos = authorRepos;
            this.articleRepos = articleRepos;
            InitializeComponent();

            Load_Author_Columns();
        }

        private void AuthorTable_Load(object sender, EventArgs e)
        {
            Load_Author_Table();
        }
        private void Load_Author_Columns()
        {
            dataGridView1.Columns.Add("", "Id");
            dataGridView1.Columns.Add("", "Name");
        }
        private void Load_Author_Table()
        {
            foreach (var it in authorRepos.GetAll())
            {
                dataGridView1.Rows.Add(it.Id, it.name);
            }
        }
        private void Clear_Author_Table()
        {
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
        }

        private void refresh_Click(object sender, EventArgs e)
        {
            Clear_Author_Table();
            Load_Author_Table();

            //authorRepos.Save();
        }

        private void delete_author_Click(object sender, EventArgs e)
        {
            try
            {
                if(articleRepos.AuthorIdCheck((int)dataGridView1.CurrentCell.Value))
                {
                    throw new Exception();
                }
                
                //
                authorRepos.Delete((int)dataGridView1.CurrentCell.Value);

            }
            catch (Exception ex)
            {
                MessageBox.Show("There is article with this author!", ex.Message, MessageBoxButtons.OK);
            }
            finally
            {
                authorRepos.Save();
            }
        }

        private void add_author_Click(object sender, EventArgs e)
        {
            authorRepos.Create(new Author(
                    int.Parse(author_Id.Text),
                    author_name.Text
                    ));
        }
    }
}
