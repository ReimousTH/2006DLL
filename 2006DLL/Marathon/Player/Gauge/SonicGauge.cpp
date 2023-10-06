#include "SonicGauge.h"

using namespace SonicTeam::Player;

SonicGauge::SonicGauge(void):IGauge((char*)"gauge")
{
	this->GaugeValue = 0;
	this->GaugeGroundTime = 0;
	this->c_gauge_max = 0;
	this->Unknown0x30 = 0;
	this->c_green = 0;
	this->c_red = 0;
	this->c_blue = 0;
	this->c_white = 0;
	this->c_sky = 0;
	this->c_yellow = 0;
	this->c_purple = 0;
	this->c_super = 0;
	this->c_gauge_heal_delay = 0;
}

SonicGauge::~SonicGauge(void) 
{

}

//
void SonicGauge::OnVarible(SonicTeam::LuaSystem**)
{

}
void SonicGauge::OnStepable(float delta)
{
	//IsGrounded
	if (!this->IsNotGrounded)
		this->GaugeGroundTime += delta;
	if (this->GaugeGroundTime >=this->c_gauge_heal_delay)
		this->AddGaugeValue(c_gauge_heal * delta);
}

float SonicGauge::GetGaugeValue()
{
	return this->GaugeValue;

}
unsigned int SonicGauge::GetGaugeLevel()
{
	return 0; // By Default
}

float SonicGauge::GetGaugeMaturity()
{
	return 0.0;
}
float SonicGauge::GetGaugePoint()
{

	return this->GaugeValue /this->c_gauge_max;
}
void SonicGauge::AddGaugeValue(float value) //Same by C++ but different in asm (
{
	if (this->c_gauge_max >=  value + this->GaugeValue )
		this->GaugeValue+=value;
	else
		this->GaugeValue = this->c_gauge_max;

}
void SonicGauge::AddMaturityValue()
{
	this->AddGaugeValue(1.0);
}
