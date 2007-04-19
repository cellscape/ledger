#include "Commodity.h"
#include "ledger.h"

using namespace ledger;

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CommodityTestCase, "numerics");

void CommodityTestCase::setUp() {}
void CommodityTestCase::tearDown() {}

void CommodityTestCase::testConstructors()
{

}

void CommodityTestCase::testPriceHistory()
{
  ptime jan17_07    = boost::posix_time::time_from_string("2007/01/17 00:00:00");
  ptime feb27_07    = boost::posix_time::time_from_string("2007/02/27 18:00:00");
  ptime feb28_07    = boost::posix_time::time_from_string("2007/02/28 06:00:00");
  ptime feb28_07sbm = boost::posix_time::time_from_string("2007/02/28 11:59:59");
  ptime mar01_07    = boost::posix_time::time_from_string("2007/03/01 00:00:00");
  ptime apr15_07    = boost::posix_time::time_from_string("2007/04/15 13:00:00");

  // jww (2007-04-17): tbd
  amount_t x1("100.10 AAPL");

  // Commodities cannot be constructed by themselves, since a great
  // deal of their state depends on how they were seen to be used.
  commodity_t& aapl(x1.commodity());

  aapl.add_price(now, amount_t("$10.20"));

  assertEqual(amount_t("$1021.02"), x1.value(now));

  assertValid(x1);
}

void CommodityTestCase::testLots()
{
  // jww (2007-04-17): tbd
}

void CommodityTestCase::testScalingBase()
{
  // jww (2007-04-17): tbd
}

void CommodityTestCase::testReduction()
{
  // jww (2007-04-17): tbd
}

