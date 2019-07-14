class tempStat
{
public:
  // Data members.
  double minimum, maximum;
  static const size_t RECORD_SIZE = 2 * sizeof(double);

  // Constructor.
  tempStat(double min = 0.0, double max = 0.0);

  // Helper method, to write a tempStat object to a file in binary format.
  void write(std::ostream & os);

  // Helper method, to read a tempStat object from a file in binary format.
  void read(std::istream & is);

  // CONTROL POSITION
  // Write tempStat at specified index in file stream.
  void write(std::ostream & os, int index);

  // CONTROL POSITION
  // Read tempStat at specified index in file stram.
  void read(std::istream &is, int indes);

  // Plus other members, as appropriate.
  // friend std::ostream &operator << (std::ostream &os, const tempStat &ts);
  // friend std::istream &operator >> (std::istream &is, tempStat &ts);
};

std::ostream &operator << (std::ostream &os, const tempStat &ts);
std::istream &operator >> (std::istream &is, tempStat &ts);
