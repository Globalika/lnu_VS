using UserApp.Models;

namespace UserApp.ViewModels
{
    public class LogoViewModel
    {
        public LogoViewModel()
        {
            _logo = new Logo(200, 200, 0,
                System.IO.Directory.GetParent(
                    System.IO.Directory.GetParent(
                        System.IO.Directory.GetCurrentDirectory()).ToString())
                + "\\Images\\social-logo.png");
        }
        private Logo _logo;
        public Logo Logo
        {
            get { return _logo; }
        }
    }
}