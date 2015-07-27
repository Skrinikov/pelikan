#pragma once

#include <protocol/memcache/codec.h>
#include <slimcache/process.h>
#include <storage/cuckoo/cuckoo.h>
#include <core/core.h>
#include <util/procinfo.h>

#include <cc_event.h>
#include <cc_log.h>
#include <channel/cc_tcp.h>

struct glob_stats {
    procinfo_metrics_st procinfo_metrics;
    event_metrics_st    event_metrics;
    server_metrics_st   server_metrics;
    worker_metrics_st   worker_metrics;
    buf_metrics_st      buf_metrics;
    tcp_metrics_st      tcp_metrics;
    cuckoo_metrics_st   cuckoo_metrics;
    codec_metrics_st    codec_metrics;
    process_metrics_st  process_metrics;
    request_metrics_st  request_metrics;
    log_metrics_st      log_metrics;
};

struct glob_stats glob_stats;
