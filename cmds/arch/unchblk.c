//unchblk.c 解开频道封闭
// Byp@MX

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
        string verb;
        if(!wizardp(me))
                return notify_fail("你想干什么？\n");
                
        if( !arg || sscanf(arg, "%s %s", arg, verb)!=2 )
                return notify_fail("指令格式：unchblk <id> [<channels> | all]\n");
        
        who = find_player(arg);
        
        if(!who) 
                return notify_fail("没有这个玩家。\n");
                
        if(who->query("chblk_on")) who->delete("chblk_on");
        if(verb == "all") {
                who->delete("chblk_channel/menpai");
                who->delete("chblk_channel/rumor");
                who->delete("chblk_channel/chat");
                who->delete("chblk_channel/se");
                who->delete("chblk_channel/jy");
        }
        who->delete("chblk_channel/"+verb);
        CHANNEL_D->do_channel(this_object(),
                "rumor","解除"+who->name()+"("+who->query("id")+")的"+verb+"频道禁制。\n");
        write("解除"+who->name()+"("+who->query("id")+")的"+verb+"频道禁制。\n");
        CHANNEL_D->do_channel(this_object(), "sys",
                me->name()+"("+me->query("id")+") 将"+who->name()+"("+who->query("id")+")的"+verb+"频道打开。\n");
        return 1;
}
