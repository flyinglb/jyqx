//unchblk.c 频道禁制
// Byp@MX

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
        string verb;
        int times = time();
        if(!wizardp(me))
                return notify_fail("你想干什么？\n");
                
        if( !arg || sscanf(arg, "%s %s", arg, verb)!=2 )
                return notify_fail("指令格式：chblk <id> [<channels> | all]\n");
        
        who = find_player(arg);
        
        if(!who) 
                return notify_fail("没有这个玩家。\n");
                
        if(who->query("chblk_on")) who->delete("chblk_on");
        who->set("chblk_channel/"+verb, times);
        CHANNEL_D->do_channel(this_object(),
		"rumor","悔天鬼王拿出一张狗皮膏药，在小火炉上细细地煨热以后，“啪”地捂住了"+who->name()+"的嘴巴。\n");
        write(who->name()+"("+who->query("id")+")的"+verb+"频道被禁制。\n");
        CHANNEL_D->do_channel(this_object(), "sys",
                me->name()+"("+me->query("id")+") 将"+who->name()+"("+who->query("id")+")的"+verb+"频道禁制。\n");
        return 1;
}
