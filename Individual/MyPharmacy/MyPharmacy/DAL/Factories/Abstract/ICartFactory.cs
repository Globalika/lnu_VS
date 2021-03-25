using MyPharmacy.DAL.Repositories.Abstract;

namespace MyPharmacy.DAL.Factories.Abstract
{
    public interface ICartFactory
    {
        ICartRepositoty GetCartRepository();
    }
}
