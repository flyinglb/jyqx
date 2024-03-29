// mudlist.c
// modified by wind

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping mud_list;
//	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size, total,count=0;

        if((time() - (int)me->query_temp("last_sys_time") < 30) && !wizardp(me)){
                write("非常规指令被禁止续使用。\n");
                return 1;
        }

	if( !find_object(DNS_MASTER) )
		return notify_fail("网路精灵并没有被载入。\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
//	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
                return notify_fail(CHINESE_MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	// 	If mudname provided, search server's database for a match
	//	and display its cooresponding address
        //	if( arg ) arg = upper_case(arg);
	
	if( !wizardp(me) )
		arg = 0;
	if(arg && arg != "" && arg != "all") {
		arg = htonn(arg);
		if(!mapp( mud_list[arg] )) {
                        write(CHINESE_MUD_NAME + "并没有和这个 Mud 取得联系。\n");
			return 1;
		}
//		if( wizardp(me) && !me->query("env/debug") )
//			printf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]);
//		else
		printf("\n有关 %s 的资讯：\n"
				"──────────────────\n"
				"中文名称：  %s\n"
				"语言：      %s\n"
				"版本：      %s\n"
				"MudOS：     %s\n"
				"Mudlib：    %s\n"
				"主机：      %s\n"
				"端口：      %s\n"
				"状态：      %s\n"
				"在线玩家：  %s\n"
				"当地时间：  %s\n"
				"──────────────────\n\n",
				mud_list[arg]["NAME"],
				undefinedp(mud_list[arg]["MUDNAME"])?
				"不详":mud_list[arg]["MUDNAME"],
				undefinedp(mud_list[arg]["ENCODING"])?
				"不详":(mud_list[arg]["ENCODING"]=="GB"?"简体汉字":"繁体汉字"),
				undefinedp(mud_list[arg]["VERSION"])?
				"不详":mud_list[arg]["VERSION"],
				undefinedp(mud_list[arg]["DRIVER"])?
				"不详":mud_list[arg]["DRIVER"],
				undefinedp(mud_list[arg]["MUDLIB"])?
				"不详":mud_list[arg]["MUDLIB"],
				mud_list[arg]["HOSTADDRESS"],
				mud_list[arg]["PORT"],
				mud_list[arg]["_dns_no_contact"]<1?
				"连线":"断开",
				undefinedp(mud_list[arg]["USERS"])?
				"不详":mud_list[arg]["USERS"],
				undefinedp(mud_list[arg]["TIME"])?
				"不详":mud_list[arg]["TIME"],
				);
		return 1;
	}

	output = 
"Mud                  中文名称                互联网IP地址     端口  人数\n"+
"────────────────────────────────────\n";
	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++) {

                if( !arg && mud_list[muds[loop]]["MUDLIB"] != MUDLIB_NAME )
			continue;
		if( arg ) {
			if( arg!="all" && mud_list[muds[loop]]["MUDLIB"] == MUDLIB_NAME )
				continue;
		}		
/*		if( mud_list[muds[loop]]["_dns_no_contact"] > 0 ) {
			if( !wizardp(me)) continue;
		}
*/
		count = loop;
//		if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
		if( htonn(muds[loop]) == htonn(INTERMUD_MUD_NAME) )
			output +=  BRED+HIY;
//                else if (mud_list[muds[loop]]["VERSION"] == MUDLIB_VERSION)
                else if (mud_list[muds[loop]]["MUDLIB"] == MUDLIB_NAME)
                        output +=  HIY;
		else
			output += NOR;

		if( undefinedp(mud_list[muds[loop]]["MUDNAME"]) ) {
			output +=  sprintf("%-43s  %-15s  %4s", 
//				upper_case(muds[loop]),
				muds[loop],
				mud_list[muds[loop]]["HOSTADDRESS"],
				mud_list[muds[loop]]["PORT"]);
		}
		else {
			output +=  sprintf("%-20s %-23s %-15s  %4s", 
//				upper_case(muds[loop]),
				muds[loop],
				undefinedp(mud_list[muds[loop]]["MUDNAME"])?
				"":mud_list[muds[loop]]["MUDNAME"],
				mud_list[muds[loop]]["HOSTADDRESS"],
				mud_list[muds[loop]]["PORT"]);
		}
		if(!undefinedp(mud_list[muds[loop]]["USERS"]))
				output+=sprintf("  %-4s", mud_list[muds[loop]]["USERS"] );
		else
				output+=sprintf("  ----", mud_list[muds[loop]]["USERS"] );

		output +=NOR"\n";
		total ++;
	}
	//	Display dumped mudlist output through user's more pager
output+="────────────────────────────────────\n";
        output += sprintf("共有 %d 个 Mud 与"+CHINESE_MUD_NAME+"连线。\n",total==0?0:total-1);
	this_player()->start_more( output );

        me->set_temp("last_sys_time",time());
	return 1;
}

int help()
{
        write("\n指令格式：mudlist            列出连线中的"CHINESE_MUD_NAME"站点。\n"
		"          mudlist <MudName>  列出指定 Mud 的信息。\n"
		"          mudlist all        列出目前所有连线中的 Mud。\n\n"
	);
	return 1;
}
