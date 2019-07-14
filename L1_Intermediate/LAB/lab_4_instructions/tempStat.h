class tempStat
{
public:
  // Data members.
  std::string name;
  double last_donation;
  double donation_amount;
  double total;
  static const size_t RECORD_SIZE = 2 * sizeof(double);

  // Constructor.
  tempStat(std::string name = "name", double donation_amount = 0.0);

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
  double read_last_donation_from_file(std::fstream &fs);
  double add_donation(double amount);
  void append_new_total_to_file(/*std::ofstream &ofile*/);

  // Plus other members, as appropriate.
  // friend std::ostream &operator << (std::ostream &os, const tempStat &ts);
  // friend std::istream &operator >> (std::istream &is, tempStat &ts);
};

std::ostream &operator << (std::ostream &os, const tempStat &ts);
std::istream &operator >> (std::istream &is, tempStat &ts);
