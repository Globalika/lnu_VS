using System.Windows;
using UserApp.ViewModels;

namespace UserApp.Views
{
    public partial class MainWindow : Window
    {
        OptionsWindow optionsWindow;
        LogoViewModel logoViewModel;
        public MainWindow()
        {
            InitializeComponent();
            logoViewModel = new LogoViewModel();
            DataContext = logoViewModel;
        }

        private void options_button_Click(object sender, RoutedEventArgs e)
        {
            optionsWindow = new OptionsWindow(ref logoViewModel);
            optionsWindow.Show();
        }
    }
}
