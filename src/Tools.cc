//#include "interface/HHAnalyzer.h"
#include "include/Tools.h"
#include "include/cp3Types.h"
#include <Math/GenVector/Boost.h>
#include <Math/VectorUtil.h>
#include <Math/Vector3D.h>

#define HH_HLT_DEBUG (false)

float getCosThetaStar_CS(const LorentzVector & h1, const LorentzVector & h2, float ebeam /*= 6500*/) {
    // cos theta star angle in the Collins Soper frame
    LorentzVector p1, p2;
    p1.SetPxPyPzE(0, 0,  ebeam, ebeam);
    p2.SetPxPyPzE(0, 0, -ebeam, ebeam);

    LorentzVector hh = h1 + h2;
    ROOT::Math::Boost boost(-hh.X() / hh.T(), -hh.Y() / hh.T(), -hh.Z() / hh.T());
    p1 = boost(p1);
    p2 = boost(p2);
    LorentzVector newh1 = boost(h1);
    ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<float>> CSaxis(p1.Vect().Unit() - p2.Vect().Unit());

    return cos(ROOT::Math::VectorUtil::Angle(CSaxis.Unit(), newh1.Vect().Unit()));
}

MELAAngles getMELAAngles(const LorentzVector &q1, const LorentzVector &q2, const LorentzVector &q11, const LorentzVector &q12, const LorentzVector &q21, const LorentzVector &q22, float ebeam /*= 6500*/) {
    MELAAngles angles;
    LorentzVector p1, p2;
    p1.SetPxPyPzE(0, 0,  ebeam, ebeam);
    p2.SetPxPyPzE(0, 0, -ebeam, ebeam);

    // set yourselves to the q1 + q2 rest frame, everyone! (note the prefix 'b' for 'boosted')
    LorentzVector X = q1 + q2;
    ROOT::Math::Boost boost(-X.X() / X.T(), -X.Y() / X.T(), -X.Z() / X.T());
    LorentzVector b_p1 = boost(p1);
    LorentzVector b_p2 = boost(p2);
    LorentzVector b_q1 = boost(q1);
    LorentzVector b_q11 = boost(q11);
    LorentzVector b_q12 = boost(q12);
    LorentzVector b_q21 = boost(q21);
    LorentzVector b_q22 = boost(q22);
    // Amend that, actually we also want some stuff in q1 or q2 rest frame
    ROOT::Math::Boost boost1(-q1.X() / q1.T(), -q1.Y() / q1.T(), -q1.Z() / q1.T());
    ROOT::Math::Boost boost2(-q2.X() / q2.T(), -q2.Y() / q2.T(), -q2.Z() / q2.T());
    LorentzVector b1_q2 = boost1(q2);
    LorentzVector b1_q11 = boost1(q11);
    LorentzVector b2_q1 = boost2(q1);
    LorentzVector b2_q21 = boost2(q21);
    // let's concentrate on three-momenta (note the prefix 'm' for three-'momenta')
    ROOT::Math::XYZVectorF m_q1(b_q1.Px(), b_q1.Py(), b_q1.Pz());
    ROOT::Math::XYZVectorF m_q11(b_q11.Px(), b_q11.Py(), b_q11.Pz());
    ROOT::Math::XYZVectorF m_q12(b_q12.Px(), b_q12.Py(), b_q12.Pz());
    ROOT::Math::XYZVectorF m_q21(b_q21.Px(), b_q21.Py(), b_q21.Pz());
    ROOT::Math::XYZVectorF m_q22(b_q22.Px(), b_q22.Py(), b_q22.Pz());
    // let's get as well three-momenta in q1 and q2 rest frame where appropriate;
    ROOT::Math::XYZVectorF m1_q2(b1_q2.Px(), b1_q2.Py(), b1_q2.Pz());
    ROOT::Math::XYZVectorF m1_q11(b1_q11.Px(), b1_q11.Py(), b1_q11.Pz());
    ROOT::Math::XYZVectorF m2_q1(b2_q1.Px(), b2_q1.Py(), b2_q1.Pz());
    ROOT::Math::XYZVectorF m2_q21(b2_q21.Px(), b2_q21.Py(), b2_q21.Pz());

    // Define reference vectors
    ROOT::Math::XYZVectorF n1(m_q11.Cross(m_q12).Unit());
    ROOT::Math::XYZVectorF n2(m_q21.Cross(m_q22).Unit());
    ROOT::Math::XYZVectorF nz(0., 0., 1.);
    ROOT::Math::XYZVectorF nsc(nz.Cross(m_q1).Unit());

    // MELA angles as taken from https://arxiv.org/pdf/1208.4018v3.pdf
    angles.phi = m_q1.Dot(n1.Cross(n2)) / fabs(m_q1.Dot(n1.Cross(n2))) * acos(- n1.Dot(n2));
    float phi1 = m_q1.Dot(n1.Cross(nsc)) / fabs(m_q1.Dot(n1.Cross(nsc))) * acos(n1.Dot(nsc));
    angles.psi = phi1 + angles.phi / 2.;
    angles.theta1 = acos(- m1_q2.Dot(m1_q11) / sqrt(m1_q2.Dot(m1_q2)) / sqrt(m1_q11.Dot(m1_q11)));
    angles.theta2 = acos(- m2_q1.Dot(m2_q21) / sqrt(m2_q1.Dot(m2_q1)) / sqrt(m2_q21.Dot(m2_q21)));
    // thetaStar is defined in the Collins-Soper frame
    ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<float>> CSaxis(b_p1.Vect().Unit() - b_p2.Vect().Unit());
    angles.thetaStar = ROOT::Math::VectorUtil::Angle(CSaxis.Unit(), b_q1.Vect().Unit());

    return angles;
}

