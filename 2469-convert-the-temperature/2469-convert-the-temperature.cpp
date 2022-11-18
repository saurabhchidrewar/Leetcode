class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin, fahr;
        kelvin = celsius + 273.15;
        fahr = celsius * 1.80 + 32.00;
        return {kelvin, fahr};
    }
};