#ifndef IEXTERNALSTORAGE_H_DEF
#define IEXTERNALSTORAGE_H_DEF

class IExternalStorage
{
public:
   IExternalStorage();
   virtual ~IExternalStorage() = 0; 

   virtual bool readDouble(char const* propertyName, double *target) = 0;
   virtual bool readInt(char const* propertyName, int *target) = 0;
   virtual bool readDoubleArray(char const* propertyName, int const rank, int const *dimensions, double *target) = 0;
   virtual bool readIntArray(char const* propertyName, int const rank, int const *dimensions, int *target) = 0;
   virtual int getRank(char const* propertyName) = 0;
   virtual bool getDimensions(char const* propertyName, int *target) = 0;
   virtual int getNumProperties() = 0;
   virtual bool getPropertyName(int index, char *target) = 0;
}; // class IExternalStorage

#endif // IEXTERNALSTORAGE_H_DEF