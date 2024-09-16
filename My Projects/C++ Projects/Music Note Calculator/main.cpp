// Assignment: Music Note Calculator


#include <iostream>
#include <cmath>

int main() 
{
    double dFrequencyRef = 16.35;
    double dTwelftRootOfTwo = 1.059463094359;
    double dSpeedOfSoundMetersPerSecond = 345.0;
    
    std::cout<< "Reference Frequency: " << dFrequencyRef << " Hz" << std::endl;
    std::cout << "Speed of Sound: " << dSpeedOfSoundMetersPerSecond << " m/s" << std::endl;
    
    //#if 1
    //C0
    int nu = 0; //v
    int k = 0;
    double frequencyOfNote = dFrequencyRef * pow(2, nu +(k/12.0));
    double wavelength = dSpeedOfSoundMetersPerSecond/frequencyOfNote;
    wavelength *= 100;
    //std::cout << "freq: " << frequencyOfNote << " wavelength " << wavelength << std::endl;
    std::cout << "Note: C0: " << " nu: " << nu << "; " << " k: " << k << "; " << "frequency: " << frequencyOfNote << " wavelengh: " << wavelength << " cm" << std::endl;
    
    //C#0
    nu = 0; //v
    k = 1;
    frequencyOfNote = dFrequencyRef * pow(2, nu +(k/12.0));
    wavelength = dSpeedOfSoundMetersPerSecond/frequencyOfNote;
    wavelength *= 100;
    //std::cout << "freq: " << frequencyOfNote << " wavelength " << wavelength << std::endl;
    std::cout << "Note: C#0: " << " nu: " << nu << "; " << " k: " << k << "; " << "frequency: " << frequencyOfNote << " wavelengh: " << wavelength << " cm" << std::endl;
    //D0
    nu = 0; //v
    k = 2;
    frequencyOfNote = dFrequencyRef * pow(2, nu +(k/12.0));
    wavelength = dSpeedOfSoundMetersPerSecond/frequencyOfNote;
    wavelength *= 100;
    //std::cout << "freq: " << frequencyOfNote << " wavelength " << wavelength << std::endl;
    std::cout << "Note: D0: " << " nu: " << nu << "; " << " k: " << k << "; " << "frequency: " << frequencyOfNote << " wavelengh: " << wavelength << " cm" << std::endl;
    
    // C4
    nu = 4; //v
    k = 0;
    frequencyOfNote = dFrequencyRef * pow(2, nu +(k/12.0));
    wavelength = dSpeedOfSoundMetersPerSecond/frequencyOfNote;
    wavelength *= 100;
    //std::cout << "freq: " << frequencyOfNote << " wavelength " << wavelength << std::endl;
    std::cout << "Note: C4: " << " nu: " << nu << "; " << " k: " << k << "; " << "frequency: " << frequencyOfNote << " wavelengh: " << wavelength << " cm" << std::endl;
    
    
    // D#7
    nu = 7; //v
    k = 3;
    frequencyOfNote = dFrequencyRef * pow(2, nu +(k/12.0));
    wavelength = dSpeedOfSoundMetersPerSecond/frequencyOfNote;
    wavelength *= 100;
    //std::cout << "freq: " << frequencyOfNote << " wavelength " << wavelength << std::endl;
    std::cout << "Note: D#7: " << " nu: " << nu << "; " << " k: " << k << "; " << "frequency: " << frequencyOfNote << " wavelengh: " << wavelength << " cm" << std::endl;
    
    // C8
    nu = 8; //v
    k = 0;
    frequencyOfNote = dFrequencyRef * pow(2, nu +(k/12.0));
    wavelength = dSpeedOfSoundMetersPerSecond/frequencyOfNote;
    wavelength *= 100;
    //std::cout << "freq: " << frequencyOfNote << " wavelength " << wavelength << std::endl;
    std::cout << "Note: C8: " << " nu: " << nu << "; " << " k: " << k << "; " << "frequency: " << frequencyOfNote << " wavelengh: " << wavelength << " cm" << std::endl;
    
    return 0;
}

