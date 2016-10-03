// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <magenta/listnode.h>

#include "xhci-trb.h"

// this struct contains state needed for a virtual root hub device
typedef struct {
    uint32_t num_ports;

    // port status for each of our ports
    usb_port_status_t*  port_status;

    // maps our virtual port index to actual root hub port index
    uint8_t* port_map;

    // interrupt requests we have pending from hub driver
    list_node_t pending_intr_reqs;

    const usb_device_descriptor_t* device_desc;
    const usb_configuration_descriptor_t* config_desc;
} xhci_root_hub_t;

mx_status_t xhci_root_hub_init(xhci_t* xhci, int rh_index);
void xhci_root_hub_free(xhci_root_hub_t* rh);
mx_status_t xhci_start_root_hubs(xhci_t* xhci);
mx_status_t xhci_rh_control(xhci_t* xhci, xhci_root_hub_t* rh, usb_setup_t* setup, void* buffer,
                            size_t* in_out_length);
bool xhci_rh_handle_intr_req(xhci_root_hub_t* rh, void* buffer, size_t* in_out_length);
void xhci_handle_root_hub_change(xhci_t* xhci);
