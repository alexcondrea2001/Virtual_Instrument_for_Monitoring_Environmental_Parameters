Project Title: Virtual Instrument for Monitoring Environmental Parameters

Project Description:

- This project presents the development of an integrated system for real-time measurement, display, and recording of environmental parameters using an Arduino Uno microcontroller connected to three sensors: DHT11 (temperature and humidity), MQ-3 (alcohol vapor detection), and MQ-5 (flammable gas detection – LPG, natural gas).

- The system acquires sensor data, transmits it to LabVIEW for processing and visualization, and automatically sends it to a Google Spreadsheet for online storage. A web interface (HTML/JavaScript) retrieves and displays the data in real-time using interactive charts and statistical summaries, providing an accessible monitoring solution for indoor air quality and safety applications.

Key Features & Implementation:

- Hardware Integration: Designed and assembled the electronic circuit using an Arduino Uno, integrating DHT11 (temperature/humidity), MQ-3 (alcohol), MQ-5 (flammable gases), and an OLED display for local readout.

- Data Acquisition (Arduino C++): Developed firmware in Arduino IDE to read all three sensors every 3 seconds, validate data, display values on the OLED screen, and transmit them via serial communication to the computer.

- Data Processing & Visualization (LabVIEW): Built a complete LabVIEW application that:

- Reads serial data from Arduino

- Calculates a thermal comfort index based on temperature and humidity

- Displays real-time charts with selectable parameters (temperature, humidity, MQ-3, MQ-5, comfort index)

- Saves data to a .txt file at user-defined intervals

- Loads and displays historical data with date filtering

- Cloud Integration (Python): Developed a Python script (labview_to_sheets.py) using gspread and oauth2client libraries to automatically send data from LabVIEW to a Google Spreadsheet, enabling remote access and data sharing.

- Web Interface (HTML/JavaScript): Created a responsive web dashboard that:

- Fetches live data from the Google Spreadsheet using a Google Apps Script API

- Displays real-time values for temperature, humidity, MQ-3, MQ-5, and comfort index

- Shows minimum and maximum recorded values for each parameter

- Visualizes data trends using Chart.js with two interactive graphs (temperature & humidity, gas concentrations)

- Auto-refreshes every 5 seconds without reloading the page

- Technologies Used: Arduino (C++), LabVIEW, Python (gspread, oauth2client), HTML, CSS, JavaScript, Chart.js, Google Sheets API, Serial Communication

Results:

- Successfully collects real-time data from all three sensors

- LabVIEW interface provides comprehensive monitoring and data logging

- Automatic cloud storage enables remote access and sharing

- Web dashboard offers intuitive, real-time visualization with historical data tracking

- Thermal comfort index enhances the system's analytical value
