/*
 * File    : rhow_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to ask a mud for a list of users logged on.
 */

// Ported to ES2 mudlib by Annihilator@ES2.

#include <command.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
#define DEBUG "debug"
#undef DEBUG
/*
* Someone has asked us for a remote who...
* Lets oblige them.
*/

void incoming_request(mapping info)
{
    string str;
    int code;
    mapping minfo;

    if(!ACCESS_CHECK(previous_object())) return;

    if (stringp(info["NAME"]) && stringp(info["PORTUDP"])) {
        if (info["NAME"] == Mud_name()) return ;

        minfo = DNS_MASTER->query_mud_info(info["NAME"]);

        // if we don't have a record of the mud get it

        if (!DNS_MASTER->dns_mudp(info["NAME"])) {
            CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("rwho request from %s rejected, ping_q sent.", info["NAME"] ) );
            PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
        }

        str = WHO_CMD->main(0, info["VERBOSE"], 1);

        if( !mapp(minfo) ) return;
                code = LOCATE_A->encoding(minfo["HOSTADDRESS"]);
        if( minfo["ENCODING"] == "GB" ) code = 0;
#ifdef DEBUG
    CHANNEL_D->do_channel(this_object(), "debug", sprintf("who %s",str));
#endif

        DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
            "@@@" + DNS_RWHO_A +
            "||NAME:" + Mud_name() +
            "||PORTUDP:" + udp_port() +
            "||RWHO:" + str +
            "||ASKWIZ:" + info["ASKWIZ"] +
            "@@@\n");
    } //if (stringp(info["NAME"]) && stringp(info["PORTUDP"]))
}

void send_rwho_q(string mud, object them, int verbose)
{
    mapping info;
    string askwiz;

    if(!ACCESS_CHECK(previous_object())
    &&  base_name(previous_object()) != WHO_CMD)    return;
    if (!them) them = this_player();
    askwiz = geteuid(them);
    info = DNS_MASTER->query_mud_info(mud);
    if (!info) return ;
    DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
        "@@@"+DNS_RWHO_Q+
        "||NAME:"+ Mud_name() +
        "||PORTUDP:"+ udp_port() +
        "||ASKWIZ:"+ askwiz +
        "||@@@\n");
}

void create() {
    seteuid(ROOT_UID);
    set("channel_id", "��·����");
}

int visiblep(object obj) { return 1; }

string get_name(object obj) { return capitalize(geteuid(obj)); }

int support_rwho_q_VERBOSE() { return 1; }


