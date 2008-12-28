
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * LlaClientServiceImpl.cpp
 * Implemtation of the LlaClientService interface. This is the class that
 * handles all the RPCs on the client side.
 * Copyright (C) 2005 - 2008 Simon Newton
 */

#include <llad/logger.h>
#include "common/protocol/Lla.pb.h"
#include "LlaClientServiceImpl.h"
#include "LlaClient.h"

namespace lla {

using namespace lla::proto;


void LlaClientServiceImpl::UpdateDmxData(
    ::google::protobuf::RpcController* controller,
    const DmxData* request,
    Ack* response,
    ::google::protobuf::Closure* done) {

  if (m_observer) {
    m_observer->NewDmx(request->universe(),
                       request->data().size(),
                       (uint8_t*) request->data().c_str(),
                       "");
  }
  done->Run();
}

} //lla
