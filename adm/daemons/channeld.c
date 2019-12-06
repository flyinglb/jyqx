// channeld.c 
// 97-10-18 add intermud channel and emote capability
//      By ken@XAJH & fuyo@XAJH 
// modify by byp@JYQXZ 2000/09/24

#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>

inherit F_DBASE;

#define BLOCK_CHAT      0
#define BLOCK_RUMOR     0
#define REMOTE_Q    "/adm/daemons/network/services/remote_q.c"

string remove_addresses(string, int all);

mapping channels = ([

    "sys":  ([  "msg_speak": NOR+HIR"【系统】"HIM"%s：%s\n" NOR,
            "msg_color": NOR+HIR,
            "wiz_only": 1,
        ]),

    "snp":  ([  "msg_speak": NOR+HIB"【窃听】%s：%s\n" NOR,
            "msg_color": NOR+WHT,
            "wiz_only": 1,
            "admin_only": 1,
        ]),

    "debug":  ([  "msg_speak": NOR+HIW"【调试】%s：%s\n" NOR,
            "msg_color": NOR+HIR,
            "wiz_only": 1,
        ]),

    "wiz":  ([  "msg_speak": NOR+HIW+"【巫师】"HIY"%s：%s\n" NOR,
            "msg_emote": NOR+HIW+"【巫师】"HIY"%s" NOR,
            "msg_color": NOR+HIY,
            "wiz_only": 1,
	]),

    "gwiz": ([  "msg_speak": NOR+HIG+"【网际巫师】"+HIY+"%s：%s\n" NOR,
            "msg_emote": NOR+HIG+"【网际巫师】"+HIY+"%s" NOR,
            "wiz_only": 1,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "channel": "gwiz",
            "msg_color": NOR+HIY,
            "filter": 1,
            "omit_address": 0, 
        ]),

    "chat": ([  "msg_speak": HIG+"【"+HIC+"闲聊"+HIG+"】"+HIC+"%s"+HIC+"：%s\n" NOR,
            "msg_emote": HIG+"【"+HIC+"闲聊"+HIG+"】"+HIC+"%s" NOR,
            "msg_color": NOR+HIC,
        ]),

    "music": ([  "msg_speak": HIG+"【"+HIY+"音乐"+HIG+"】"+HIY+"%s"+HIY+"唱道：%s\n" NOR,
            "msg_color": NOR+HIY,
        ]),

    "rumor":    ([  "msg_speak": HIM"【"+HIR+"谣言"+HIM+"】"+HIR+"%s"+HIR+"：%s\n" NOR,
            "msg_emote": HIM"【"+HIR+"谣言"+HIM+"】"HIR"%s" NOR,
            "msg_color": NOR+HIR,
            "anonymous": "某人",
        ]),

    "menpai":([  "msg_speak": HIY"【"+HIW+"%s"+HIY+"】"+HIG+"%s"+HIG+": %s\n" NOR,
            "msg_emote": HIY"【"+HIW+"%s"+HIY+"】"+HIG+"%s" NOR,
            "msg_color": NOR+HIG,
            "party_only": 1,
        ]),

    "es":   ([  "msg_speak": HIC+"【"+HIW+"网际闲聊"+HIC+"】"+HIG+"%s"+HIG+"：%s\n" NOR,
            "msg_emote": HIC+"【"+HIW+"网际闲聊"+HIC+"】"+HIG+"%s" NOR,
            "msg_color": NOR+HIG,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "channel": "es",
            "filter": 1,
            "omit_address": 0, 
        ]),

    "jy":   ([  "msg_speak": HIC"【"+HBCYN+HIW+"金庸群侠"+NOR+HIC+"】"HIW"%s"+HIW+"：%s\n" NOR,
            "msg_emote": HIC"【"HBCYN+HIW+"金庸群侠"+NOR+HIC+"】"HIW"%s" NOR,
            "msg_color": NOR+HIW,
            "jy_only": 1,
            "intermud": GCHANNEL,
            "intermud_emote": 1,
            "channel": "jy",
            "filter": (: $1["MUDLIB"] == "JYQXII" :) ,
            "omit_address": 0, 
        ]),
]);

void create()
{
    // This is required to pass intermud access check.
    seteuid(getuid());
    set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote, int remote)
{
        object *ob;
        string *tuned_ch, who;
        string arg_bk,self_emote;
        self_emote = arg;

        // Check if this is a channel emote.
        if( sizeof(verb) > 2 ) {
                if( verb[sizeof(verb)-1] == '*' ) {
                        emote = 1;
                        verb = verb[0..<2];
                }
        }

        // Check if this is a channel messsage.
        if( !mapp(channels) || undefinedp(channels[verb]) ) return 0;

        // check if this channel support emote message. 
        if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
                write("对不起，这个频道不支持 emote 。\n");
                return 1;
        }
        //now we can be sure it's indeed a channel message:
        if (!stringp(arg) || arg == "" || arg == " ") arg = "...";
        else arg_bk = arg;
    
        if(remote) arg_bk = arg;

        // check if one can write to channels
        // only block rumor or chat...
	    if ( userp(me) && !wizardp(me)) {
		    if(time()-(int)me->query("chblk_channel/all")<3600)
			    return notify_fail("你所有的聊天频道都被关闭了！\n");
		
		    switch (verb) {
			    case "rumor" : 
			        if (time() - (int)me->query("chblk_channel/rumor") < 3600)
				        return notify_fail("你的谣言频道被关闭了！\n");
				    break;
			    case "music" : 
			        if (time() - (int)me->query("chblk_channel/music") < 3600)
				        return notify_fail("你的音乐频道被关闭了！\n");
				    break;
			    case "chat"  : 
			        if (time() - (int)me->query("chblk_channel/chat") < 3600)
				        return notify_fail("你的聊天频道被关闭了！\n");
				    break;
			    case "menpai" : 
			        if (time() - (int)me->query("chblk_channel/shout") < 3600)
				        return notify_fail("你的门派频道被关闭了！\n");
				    break;
			    case "es"    : 
			        if (time() - (int)me->query("chblk_channel/es") < 3600)
 				        return notify_fail("你的网际闲聊频道被关闭了！\n");
				    break;
			    case "jy"    : 
			        if (time() - (int)me->query("chblk_channel/jy") < 3600)
				        return notify_fail("你的金庸群侠频道被关闭了！\n");
				    break;
            }
	    }
    
    if( userp(me) ) {
        if( channels[verb]["wiz_only"] && !wizardp(me)) return 0;
        if( channels[verb]["admin_only"] && ( wizhood(me) != "(admin)" && wizhood(me) != "(superuser)") ) return 0;
        if(!wizardp(me) && verb == "rumor") {
            if(me->query("jing") > 50) me->add("jing", 0 - random(30));
            else return notify_fail("你太累，已经无法散播谣言了！\n");
            
        }   
    
        if( (verb=="menpai") && !me->query("family/family_name") )
            return notify_fail("你并没有加入任何门派。\n"); 

        if(channels[verb]["jy_filter"] && ( me->query("age") < 20) && !wizardp(me))
            return notify_fail("你年纪还小，不能使用金庸群侠频道！\n");
        if((int)me->query("mud_age")<900&&!wizardp(me))
                return notify_fail("你的年纪太小了，还不能使用公开频道说话。\n");
    
        // check if same channel message but not wizard
        if( !wizardp(me) && (arg == (string)me->query_temp("last_channel_msg")) )
            return notify_fail("公共频道说话请不要重复相同讯息！\n");

        if( userp(me) && !wizardp(me)) {
            me->set_temp("last_channel_msg", arg);
            me->add_temp("channel_msg_cnt", 1);
            if (me->query_temp("channel_msg_cnt")>1)
                if (time()-me->query_temp("chat_time")<4) {
                    me->set("chblk_channel/"+verb,time());
                    do_channel( this_object(), "rumor"
                    , sprintf("悔天鬼王拿出一张狗皮膏药，在小火炉上细细地煨热以后，“啪”地捂住了%s的嘴巴。\n"
                    , me->name(1) ));
                    return 1;
                } else {
                    me->set_temp("chat_time",time());
                    me->delete_temp("channel_msg_cnt");
                }
        }

        if (channels[verb]["party_only"]) {
            channels[verb]["msg_speak"] = HIY+"【"+me->query("family/family_name")+"】"+HIC+"%s：%s\n"+NOR;
            channels[verb]["msg_emote"] = HIY+"【"+me->query("family/family_name")+"】"+HIC+"%s"+NOR;
        }
        
        // If we speaks something in this channel, then must tune it in.
        tuned_ch = me->query("channels");
        
        if( !pointerp(tuned_ch) )
            me->set("channels", ({ verb }) );
        else if( member_array(verb, tuned_ch) == -1 )
            me->set("channels", tuned_ch + ({ verb }) );
    }

    // Support of channel emote
    if( emote  && me->is_character() && !remote) {
        string vb, emote_arg;

        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
            vb = arg;
            emote_arg = "";
        }

        if( channels[verb]["intermud_emote"] )
            arg = EMOTE_D->do_emote(me, vb, emote_arg, 3);
        if( verb == "rumor" && (wizardp(me) || random(10) < 8) )
             arg = EMOTE_D->do_emote(me, vb, emote_arg, 2, channels[verb]["anonymous"]);
        else arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);

        if (!arg && emote) {
            // we should only allow chinese emote.
            if( (int)vb[0] < 160 ) return 0;
            arg = sprintf("%s(%s@%s)%s\n",me->name(),
            me->query("id"),Mud_name(),arg_bk);
            if( verb == "rumor" ) {
                if( userp(me) )
                    arg = sprintf("%s%s\n",channels[verb]["anonymous"],vb);
            }
        }
                
        if( !arg ) {
            if( channels[verb]["anonymous"] ) 
                arg = channels[verb]["anonymous"]+vb+" "+emote_arg+"\n"; 
            else if( channels[verb]["intermud_emote"] )
                arg = sprintf("%s(%s@%s)%s %s\n", me->name(1)
                      , capitalize(me->query("id")), INTERMUD_MUD_LONG_NAME
                      , vb, emote_arg);
                        else arg = me->name()+vb+" "+emote_arg+"\n"; 
        }
    }// Support end
    
    // Make the identity of speaker.
    if( channels[verb]["anonymous"] ) {
        who = channels[verb]["anonymous"];
/*
        if (userp(me))
			if (random(10)>8)
			    who=me->name(1) + "(" + capitalize(me->query("id")) + ")";
			else
                do_channel( this_object(), "sys", sprintf("%s(%s)躲了起来造谣。", me->name(1),me->query("id")));
*/
        if( !wizardp(me) && interactive(me) && random(10)>8 )
                who=me->name(1) + "(" + capitalize(me->query("id")) + ")";
        else    do_channel( this_object(), "sys", 
                sprintf("%s(%s)躲了起来造谣。", me->name(1),me->query("id")));

	} else if(me && (userp(me) || !stringp(who = me->query("channel_id")) )){
                if (me->name()!=me->name(1) && emote)
                do_channel( this_object(), "sys", sprintf(HIR"%s(%s)"+HIW+"扮%s!"
                          , me->name(1),me->query("id"),me->name()));
                who = me->name(1) + "(" + me->query("id") + ")";
    }

    if( verb == "arch" ) {
        who = sprintf("%s", RANK_D->query_rank(me));
        who = replace_string(who," ","");
        who = replace_string(who,NOR,"");
        who +=(me->name(1)+"("+capitalize(me->query("id"))+")");
    }


    // Ok, now send the message to those people listening us.
    ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
    if( !arg || arg == "" || arg == " " ) arg = "...";

    if( emote ) {
        string localmsg;
        string ecol = channels[verb]["msg_color"];
        
        if(remote) arg = arg_bk;
        
        if(remote && !arg)
            arg = me->name()+"("+me->query("id")+"@"+INTERMUD_MUD_LONG_NAME+")"+arg+"\n";
        
        if (!stringp(arg)) return 0;
        
        localmsg = arg;

        if ( channels[verb]["msg_emote"] )
            localmsg = remove_addresses(arg, 0); // 98-1-22 14:30

        if( channels[verb]["omit_address"] ) localmsg = remove_addresses(arg, 1);
        else if( channels[verb]["intermud_emote"] ) localmsg = remove_addresses(arg, 0);

        if(!stringp(localmsg)) return 0;
        
        message( "channel:" + verb, sprintf( channels[verb]["msg_emote"],replace_string(localmsg,NOR,ecol)), ob );
    
    } else
        message( "channel:" + verb, sprintf( channels[verb]["msg_speak"], who, arg ), ob );

    if( arrayp(channels[verb]["extra_listener"]) ) {
        channels[verb]["extra_listener"] -= ({ 0 });
        if( sizeof(channels[verb]["extra_listener"]) )
            channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
    }
      
    if( !undefinedp(channels[verb]["intermud"]) && me->is_character()) {
        channels[verb]["intermud"]->send_msg(
        channels[verb]["channel"], me->query("id"), me->name(1), arg, emote,
        channels[verb]["filter"] );
    }

    return 1;
}

int filter_listener(object ppl, mapping ch)
{
    // Don't bother those in the login limbo.
    if( !environment(ppl) ) return 0;

    if( ch["wiz_only"] ) 
        if( userp(ppl) )    
            return wizardp(ppl);

    return 1;
}

void register_relay_channel(string channel)
{
    object ob;
    ob = previous_object();
    if( undefinedp(channels[channel]) || !ob) return;
    if( arrayp(channels[channel]["extra_listener"]) ) {
    if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
    channels[channel]["extra_listener"] += ({ ob });
    }
    else  channels[channel]["extra_listener"] = ({ ob });
}

string remove_addresses(string msg, int all)
{
    int i;
    mixed tmp;
    string pattern;

    if(!stringp(msg)) return msg;
    if( all )
        pattern = "[(][A-Za-z]+@[a-zA-Z]+[0-9]+[.]?[)]";
    else
        pattern = "[(][A-Za-z]+@"+Mud_name()+"[)]";

    tmp = reg_assoc(msg, ({pattern}), ({1}));

    if(!arrayp(tmp)) return msg;
    msg = "";
    for(i=0; i< sizeof(tmp[0]); i++)
        if( tmp[1][i] == 0 ) msg += tmp[0][i];
    return msg;
}
int family_listener(object ppl, string str)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl)) return 0;
        
        if(wizardp(ppl) || ppl->query("family/family_name")==str ) return 1;
        else return 0;
}
