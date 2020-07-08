/*
	Opec is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Opec is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Opec.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <common/general.h>
#include "monitor.h"

namespace Opec {
	Monitor::Monitor(Opec::server *server_h, Opec::client *client_h, Opec::tls_server *tls_server_h, Opec::tls_client *tls_client_h,
		Opec::connection_hdl con, const std::string &uri, int64_t id) : 
		Connection(server_h, client_h, tls_server_h, tls_client_h, con, uri, id), active_time_(0){
	}

	void Monitor::SetSessionId(const std::string &session_id) {
		session_id_ = session_id;
	}

	void Monitor::SetActiveTime(int64_t current_time) {
		active_time_ = current_time;
	}

	int64_t Monitor::GetActiveTime() const {
		return active_time_;
	}

	bool Monitor::IsActive() const {
		return active_time_ > 0;
	}

	utils::InetAddress Monitor::GetRemoteAddress() const {
		utils::InetAddress address = GetPeerAddress();
		return address;
	}

	std::string Monitor::GetPeerNodeAddress() const {
		return Opec_node_address_;
	}

	void Monitor::SetOpecInfo(const protocol::ChainStatus &hello) {
		monitor_version_ = hello.monitor_version();
		Opec_ledger_version_ = hello.ledger_version();
		Opec_version_ = hello.Opec_version();
		Opec_node_address_ = hello.self_addr();
	}

	bool Monitor::SendHello(int32_t listen_port, const std::string &node_address, std::error_code &ec) {
		protocol::ChainStatus hello;
		hello.set_monitor_version(Opec::General::MONITOR_VERSION);
		hello.set_ledger_version(Opec::General::LEDGER_VERSION);
		hello.set_Opec_version(Opec::General::Opec_VERSION);
		hello.set_self_addr(node_address);

		return SendRequest(protocol::CHAIN_HELLO, hello.SerializeAsString(), ec);
	}
}

