# Hydro-Sense-Precision-Agriculture-and-Water-Conservation

The software component integrates these calculations and data collection, providing real-time information to farmers through a user-friendly GUI frontend displayed on an app. Our findings demonstrate the effectiveness of Hydro-Sense in conserving water while ensuring optimal plant growth. Agriculture is made more sustainable and effective by Hydro-Sense, which optimizes crop output while conserving water by regulating the supply of water based on plant requirements.


Our methodology for developing the "Hydro-Sense" system involved several key steps, including sensor selection, data collection, algorithm development, and hardware-software integration. This section outlines the detailed methodology followed in each step of the project.


1. Sensor Selection:
We selected the DHT22 sensor for humidity measurement due to its high accuracy and reliability. For temperature measurement, we chose the DS18B20 sensor for its precision and digital output. In addition, we measured the soil moisture content using a capacitive soil moisture sensor, which offers precise and timely data required to determine the water requirements of plants.

2. Data Collection:
The sensors were connected to an Arduino Uno microcontroller board, which served as the central processing unit for data collection. The Arduino Uno collected humidity, temperature, and soil moisture data from the sensors at regular intervals. The collected data was then processed and used for further calculations.

3. Algorithm Development:
We developed algorithms to calculate the urgency score of each plant for water based on the collected sensor data. The urgency score calculation algorithm takes into account the weighted sum of temperature, humidity, and soil moisture values, with weights adjusted according to the importance of each parameter in determining plant water requirements. The formula for urgency score which will give a value between 0 & 1, is as follows:
Urgency Score (U)=[ω_temp×(Temperature-Temp Threshold)+ω_humidity×(Humidity-Humidity Threshold)+ ω_moisture  ×(Soil Moisture-Moisture Threshold)] 




Where:
- ω is the weightage of each parameter 
- the thresholds are defined as the extreme values of each parameter beyond which the plant will take serious damage and start to die. 

4. Irrigation Time Calculation:
The system determines how long each plant needs to be irrigated based on its urgency ranking. The formula for irrigation time calculation is as follows: 
Irrigation Time(T)=(A×(K_C+ET)×60×U)/(F×(1000∕P) ) 

Where:
- Kc is the crop coefficient; 
- A is the garden area in meters squared. 
-"ET" stands for evapotranspiration in milligrams per day. 
- P is the number of irrigation periods, and 
- F is the water outflow per valve in m3/h. 
- The urgency score is U.

5. Water Distribution Calculation:

The irrigation time and the urgency score are used by the system to determine how much water needs to be allocated. The amount of water retained is directly correlated with the duration of each water cycle. The formula for water distribution calculation is as follows:
Water Distribution(C)=((F×N×1000)×U×T)/60 

Where,
- C is the amount of water to be distributed
- N is the number of irrigation periods. 
- T is the irrigation time as mentioned above 
- F is the outgoing flow of water per valve in m3/h
- U is the urgency score.

6. Actual Water Distribution Calculation:
The actual amount of water to be provided to each plant is calculated considering the available water in the storage. The formula for actual water distribution calculation is as follows:
 plant(i)= (ωi/ωt)×((c×n)/d)

Where:
- ωi is the water requirement for plant i,
- ωt is the total water requirement of all plants,
- c is the total water capacity,
- n is the water sent to each plant, and
- d is the number of days water required.

7. Hardware-Software Integration:
The Arduino Uno microcontroller board, along with the sensors, was integrated with a graphical user interface (GUI) frontend developed using Java in Android Studio. This frontend displayed real-time data, including plant water urgency, irrigation time, and water distribution, allowing farmers to monitor and manage water usage efficiently.
