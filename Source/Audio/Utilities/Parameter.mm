//
//  Parameter.mm
//  GestureController
//
//  Created by Govinda Ram Pingali on 4/8/14.
//  Copyright (c) 2014 GTCMT. All rights reserved.
//

#include "Parameter.h"


Parameter::Parameter()
{
    m_fAlpha = 0.99f;
    m_fParameter = 0.0f;
}


Parameter::~Parameter()
{
    
}


void Parameter::setAlpha(float newAlpha)
{
    m_fAlpha = newAlpha;
}


float Parameter::process(float value)
{
    m_fParameter = (value * (1.0f - m_fAlpha)) + (m_fParameter * m_fAlpha);
    
    return m_fParameter;
}