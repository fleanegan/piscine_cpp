//
// Created by fleanegan on 03.06.22.
//

#ifndef EX01_DATA_HPP
#define EX01_DATA_HPP

class Data {
public:
private:
	std::string str;
public:
	int arr[3];

	Data();
	Data(const Data &other);
	Data &operator=(const Data &);
	~Data();

	const std::string &getStr() const;
};

#endif //EX01_DATA_HPP
