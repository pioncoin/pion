// Copyright (c) 2014-2018 The Dash Core developers
// Copyright (c) 2018 The Pion Core Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "validation.h"

#include "test/test_pion.h"

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(subsidy_tests, TestingSetup)

BOOST_AUTO_TEST_CASE(block_subsidy_test)
{
    const Consensus::Params& consensusParams = Params(CBaseChainParams::MAIN).GetConsensus();

    uint32_t nPrevBits;
    int32_t nPrevHeight;
    CAmount nSubsidy;

    // details for block 4249 (subsidy returned will be for block 4250)
    // random block in the first year - 20 coins
    nPrevBits = 0x1c4a47c4;
    nPrevHeight = 4249;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 20 * COIN);

    // details for block 0 (subsidy returned will be for block 1)
    // Dev foundation pre-mine 1,000,000 coins
    nPrevBits = 0x1c4a47c4;
    nPrevHeight = 0;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 1000000 * COIN);

    // details for block 1 (subsidy returned will be for block 2)
    // Marketing premine 350,000 coins
    nPrevBits = 0x1c29ec00;
    nPrevHeight = 1;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 250000 * COIN);

    // details for block 2189 (subsidy returned will be for block 2189)
    // First Bonus block. 100 + 20 coins
    nPrevBits = 0x1c29ec00;
    nPrevHeight = 2189;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 120 * COIN);

    // details for block 262800 (subsidy returned will be for block 262801)
    // first block in year 2
    nPrevBits = 0x1c08ba34;
    nPrevHeight = 262800;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 1681920000ULL);

    // details for block 264989 (subsidy returned will be for block 264990)
    // Bonus block in the 2nd year
    nPrevBits = 0x1b10cf42;
    nPrevHeight = 264989;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 11681920000ULL);

    // details for block 1314000 (subsidy returned will be for block 1314000)
    // 5th year first block
    nPrevBits = 0x1b11548e;
    nPrevHeight = 1314000;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 841214386ULL);

    // details for block 1316189 (subsidy returned will be for block 1316190)
    // Make sure no bonus blocks after 5th year
    nPrevBits = 0x1b10d50b;
    nPrevHeight = 1316189;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 841214386ULL);
}

BOOST_AUTO_TEST_SUITE_END()
