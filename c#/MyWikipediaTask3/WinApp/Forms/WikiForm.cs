using MyWikipediaTask3.Entities;
using MyWikipediaTask3.Repository.Impl;
using System;
using System.Windows.Forms;
using WinApp.AuthorsForms;

namespace WinApp
{
    public partial class WikiForm : Form
    {
        BaseRepository<Article> articleRepos;
        AuthorRepository authorRepos;
        AuthorTableForm authorForm;

        public WikiForm()
        {
            articleRepos = new ArticleRepository();
            authorRepos = new AuthorRepository();
            authorForm = new AuthorTableForm(authorRepos, (ArticleRepository)articleRepos);
            InitializeComponent();

            Load_Article_Columns();
        }

        private void WikiForm_Load(object sender, EventArgs e)
        {
            Load_Article_Table();
        }
        private void Clear_Article_Table()
        {
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
        }

        private void Load_Article_Columns()
        {
            dataGridView1.Columns.Add("", "Id");
            dataGridView1.Columns.Add("", "Autor_Name");
            dataGridView1.Columns.Add("", "Title");
            dataGridView1.Columns.Add("", "Genre");
        }
        private void Load_Article_Table()
        {
            foreach (var it in articleRepos.GetAll())
            {
                string name = authorRepos.GetById(it.FkAuthorId).name;
                dataGridView1.Rows.Add(it.Id, name, it.title, it.genre);
            }
        }
        private void refresh_button_Click(object sender, EventArgs e)
        {
            Clear_Article_Table();
            Load_Article_Table();
            //
            //
            //articleRepos.Save();
        }

        private void delete_article_Click(object sender, EventArgs e)
        {
            articleRepos.Delete((int)dataGridView1.CurrentCell.Value);
            articleRepos.Save();
            //
            //Clear_Article_Table();
            //Load_Article_Table();
        }

        private void add_article_Click(object sender, EventArgs e)
        {
            try
            {
                var author = authorRepos.GetById(int.Parse(this.author_Id.Text));
                articleRepos.Create(new Article(
                    int.Parse(article_Id.Text),
                    author.Id,
                    article_title.Text,
                    article_genre.Text
                    ));
            }
            catch (Exception ex)
            {
                MessageBox.Show("There is no author with this Id!", ex.Message, MessageBoxButtons.OK);
            }
            finally
            {
                articleRepos.Save();
                //
                //Clear_Article_Table();
                //Load_Article_Table();
            }
        }

        private void author_table_button_Click(object sender, EventArgs e)
        {
            authorForm.Show();
        }
    }
}
