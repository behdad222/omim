#include "testing/testing.hpp"

#include "integration_tests/osrm_test_tools.hpp"

#include "../indexer/mercator.hpp"

using namespace routing;

namespace
{
  UNIT_TEST(RussiaMoscowLenigradskiy39GerPanfilovtsev22RouteTest)
  {
    integration::CalculateRouteAndTestRouteLength(integration::GetAllMaps(),
                                                  {37.53758809983519, 67.536162466434234}, {0., 0.},
                                                  {37.40993977728661, 67.644784047393685}, 14296.);
  }

  UNIT_TEST(RussiaMoscowGerPanfilovtsev22SolodchaPravdiRouteTest)
  {
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), {37.409929478750627, 67.644798619710073}, {0., 0.},
        {39.836562407458047, 65.774372510437971}, 239426.);
  }

  UNIT_TEST(UKRugbyStIvesRouteTest)
  {
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), {-1.2653036222483705, 61.691304855049886}, {0., 0.},
        {-5.4799407508360218, 58.242809563579847}, 455902.);
  }

  UNIT_TEST(RussiaMoscowLenigradskiy39ItalySienaCenterRouteTest)
  {
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), {37.537596024929826, 67.536160359657288}, {0., 0.},
        {11.327927635052676, 48.166256203616726}, 2870710.);
  }

  UNIT_TEST(RussiaMoscowLenigradskiy39EnglandLondonCenterRouteTest)
  {
    //@todo put down a correct route length when router is fixed
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), {37.537572384446207, 67.536189683408367}, {0., 0.},
        {-0.084976483156808751, 60.298304898120428}, 1000.);
  }

  UNIT_TEST(RussiaMoscowLenigradskiy39RepublicOfSouthAfricaCapeTownCenterRouteTest)
  {
    //@todo put down a correct route length when router is fixed
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), {37.537543510152318, 67.536217686389165}, {0., 0.},
        {18.542688617866236, -36.095015335418523}, 1000.);
  }

  UNIT_TEST(ArbatBaliCrimeanForwardCrossMwmTest)
  {
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), MercatorBounds::FromLatLon(46.152324, 34.804955), {0., 0.},
        MercatorBounds::FromLatLon(45.35697, 35.369712), 105000.);
  }

  UNIT_TEST(ArbatBaliCrimeanBackwardCrossTest)
  {
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), MercatorBounds::FromLatLon(45.356971, 35.369712), {0., 0.},
        MercatorBounds::FromLatLon(46.152324, 34.804955), 105000.);
  }

  UNIT_TEST(AlbaniaToMontenegroCrossTest)
  {
    // Road from Albania to Montenegro. Test turnaround finding at border (when start/stop OSRM
    // points are inside borders and one of segments has outside points).
    // Forward
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), MercatorBounds::FromLatLon(42.01535, 19.40044), {0., 0.},
        MercatorBounds::FromLatLon(42.01201, 19.36286), 3674.);
    // And backward case
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), MercatorBounds::FromLatLon(42.01201, 19.36286), {0., 0.},
        MercatorBounds::FromLatLon(42.01535, 19.40044), 3674.);
  }

  UNIT_TEST(CanadaBridgeCrossToEdwardIsland)
  {
    // Forward
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), MercatorBounds::FromLatLon(46.13418, -63.84656), {0., 0.},
        MercatorBounds::FromLatLon(46.26739,-63.63907), 23000.);
    // And backward case
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), MercatorBounds::FromLatLon(46.26739, -63.63907), {0., 0.},
        MercatorBounds::FromLatLon(46.13418, -63.84656), 23000.);
  }

  UNIT_TEST(RussiaFerryToCrimea)
  {
    // Forward
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), MercatorBounds::FromLatLon(45.38053, 36.73226), {0., 0.},
        MercatorBounds::FromLatLon(45.36078, 36.60866), 13000.);
    // And backward case
    integration::CalculateRouteAndTestRouteLength(
        integration::GetAllMaps(), MercatorBounds::FromLatLon(45.36078, 36.60866), {0., 0.},
        MercatorBounds::FromLatLon(45.38053, 36.73226), 13000.);
  }
}
