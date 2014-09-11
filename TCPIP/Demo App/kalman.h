#ifndef _Kalman_h
#define _Kalman_h

//Declaramos las variables globales, denotadas por "kx_"
double kx_Q_angle; // Process noise variance for the accelerometer
double kx_Q_bias; // Process noise variance for the gyro bias
double kx_R_measure; // Measurement noise variance - this is actually the variance of the measurement noise

double kx_angle; // The angle calculated by the Kalman filter - part of the 2x1 state vector
double kx_bias; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
double kx_rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

double kx_P[2][2]; // Error covariance matrix - This is a 2x2 matrix
double kx_K[2]; // Kalman gain - This is a 2x1 vector
double kx_y; // Angle difference
double kx_S; // Estimate error

double ky_Q_angle; // Process noise variance for the accelerometer
double ky_Q_bias; // Process noise variance for the gyro bias
double ky_R_measure; // Measurement noise variance - this is actually the variance of the measurement noise

double ky_angle; // The angle calculated by the Kalman filter - part of the 2x1 state vector
double ky_bias; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
double ky_rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

double ky_P[2][2]; // Error covariance matrix - This is a 2x2 matrix
double ky_K[2]; // Kalman gain - This is a 2x1 vector
double ky_y; // Angle difference
double ky_S; // Estimate error


void KalmanXY_Inicializacion()
{
    kx_Q_angle = 0.001;
    kx_Q_bias = 0.003;
    kx_R_measure = 0.03;
    kx_angle = 0; // Reset the angle
    kx_bias = 0; // Reset bias
    kx_P[0][0] = 0;
    kx_P[0][1] = 0;
    kx_P[1][0] = 0;
    kx_P[1][1] = 0;

    ky_Q_angle = 0.001;
    ky_Q_bias = 0.003;
    ky_R_measure = 0.03;
    ky_angle = 0; // Reset the angle
    ky_bias = 0; // Reset bias
    ky_P[0][0] = 0;
    ky_P[0][1] = 0;
    ky_P[1][0] = 0;
    ky_P[1][1] = 0;
}

double KalmanX_getAngle(double newAngle, double newRate, double dt)
{
    // KasBot V2  -  Kalman filter module - http://www.x-firm.com/?page_id=145
    // Modified by Kristian Lauszus
    // See my blog post for more information: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it

    // Discrete Kalman filter time update equations - Time Update ("Predict")
    // Update xhat - Project the state ahead
    /* Step 1 */
    kx_rate = newRate - kx_bias;
    kx_angle += dt * kx_rate;
    
    // Update estimation error covariance - Project the error covariance ahead
    /* Step 2 */
    kx_P[0][0] += dt * (dt*kx_P[1][1] - kx_P[0][1] - kx_P[1][0] + kx_Q_angle);
    kx_P[0][1] -= dt * kx_P[1][1];
    kx_P[1][0] -= dt * kx_P[1][1];
    kx_P[1][1] += kx_Q_bias * dt;

    // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
    // Calculate Kalman gain - Compute the Kalman gain
    /* Step 4 */
    kx_S = kx_P[0][0] + kx_R_measure;
    /* Step 5 */
    kx_K[0] = kx_P[0][0] / kx_S;
    kx_K[1] = kx_P[1][0] / kx_S;
    
    // Calculate angle and bias - Update estimate with measurement zk (newAngle)
    /* Step 3 */
    kx_y = newAngle - kx_angle;
    /* Step 6 */
    kx_angle += kx_K[0] * kx_y;
    kx_bias += kx_K[1] * kx_y;
    
    // Calculate estimation error covariance - Update the error covariance
    /* Step 7 */
    kx_P[0][0] -= kx_K[0] * kx_P[0][0];
    kx_P[0][1] -= kx_K[0] * kx_P[0][1];
    kx_P[1][0] -= kx_K[1] * kx_P[0][0];
    kx_P[1][1] -= kx_K[1] * kx_P[0][1];
    
    return kx_angle;
}

void KalmanX_setAngle(double newAngle)
{
    kx_angle = newAngle;
} // Used to set angle, this should be set as the starting angle

double KalmanX_getRate()
{
    return kx_rate;
} // Return the unbiased rate

/* These are used to tune the Kalman filter */
void KalmanX_setQangle(double newQ_angle)
{
    kx_Q_angle = newQ_angle;
}

void KalmanX_setQbias(double newQ_bias)
{
    kx_Q_bias = newQ_bias;
}

void KalmanX_setRmeasure(double newR_measure)
{
    kx_R_measure = newR_measure;
}

double KalmanX_getQangle()
{
    return kx_Q_angle;
}

double KalmanX_getQbias()
{
    return kx_Q_bias;
}

double KalmanX_getRmeasure()
{
    return kx_R_measure;
}


////----------------------------Y
double KalmanY_getAngle(double newAngle, double newRate, double dt)
{
    // KasBot V2  -  Kalman filter module - http://www.x-firm.com/?page_id=145
    // Modified by Kristian Lauszus
    // See my blog post for more information: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it

    // Discrete Kalman filter time update equations - Time Update ("Predict")
    // Update xhat - Project the state ahead
    /* Step 1 */
    ky_rate = newRate - ky_bias;
    ky_angle += dt * ky_rate;

    // Update estimation error covariance - Project the error covariance ahead
    /* Step 2 */
    ky_P[0][0] += dt * (dt*ky_P[1][1] - ky_P[0][1] - ky_P[1][0] + ky_Q_angle);
    ky_P[0][1] -= dt * ky_P[1][1];
    ky_P[1][0] -= dt * ky_P[1][1];
    ky_P[1][1] += ky_Q_bias * dt;

    // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
    // Calculate Kalman gain - Compute the Kalman gain
    /* Step 4 */
    ky_S = ky_P[0][0] + ky_R_measure;
    /* Step 5 */
    ky_K[0] = ky_P[0][0] / ky_S;
    ky_K[1] = ky_P[1][0] / ky_S;

    // Calculate angle and bias - Update estimate with measurement zk (newAngle)
    /* Step 3 */
    ky_y = newAngle - ky_angle;
    /* Step 6 */
    ky_angle += ky_K[0] * ky_y;
    ky_bias += ky_K[1] * ky_y;

    // Calculate estimation error covariance - Update the error covariance
    /* Step 7 */
    ky_P[0][0] -= ky_K[0] * ky_P[0][0];
    ky_P[0][1] -= ky_K[0] * ky_P[0][1];
    ky_P[1][0] -= ky_K[1] * ky_P[0][0];
    ky_P[1][1] -= ky_K[1] * ky_P[0][1];

    return ky_angle;
}

void KalmanY_setAngle(double newAngle)
{
    ky_angle = newAngle;
} // Used to set angle, this should be set as the starting angle

double KalmanY_getRate()
{
    return ky_rate;
} // Return the unbiased rate

/* These are used to tune the Kalman filter */
void KalmanY_setQangle(double newQ_angle)
{
    ky_Q_angle = newQ_angle;
}

void KalmanY_setQbias(double newQ_bias)
{
    ky_Q_bias = newQ_bias;
}

void KalmanY_setRmeasure(double newR_measure)
{
    ky_R_measure = newR_measure;
}

double KalmanY_getQangle()
{
    return ky_Q_angle;
}

double KalmanY_getQbias()
{
    return ky_Q_bias;
}

double KalmanY_getRmeasure()
{
    return ky_R_measure;
}


#endif
