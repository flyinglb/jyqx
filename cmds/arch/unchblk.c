//unchblk.c �⿪Ƶ�����
// Byp@MX

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
        string verb;
        if(!wizardp(me))
                return notify_fail("�����ʲô��\n");
                
        if( !arg || sscanf(arg, "%s %s", arg, verb)!=2 )
                return notify_fail("ָ���ʽ��unchblk <id> [<channels> | all]\n");
        
        who = find_player(arg);
        
        if(!who) 
                return notify_fail("û�������ҡ�\n");
                
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
                "rumor","���"+who->name()+"("+who->query("id")+")��"+verb+"Ƶ�����ơ�\n");
        write("���"+who->name()+"("+who->query("id")+")��"+verb+"Ƶ�����ơ�\n");
        CHANNEL_D->do_channel(this_object(), "sys",
                me->name()+"("+me->query("id")+") ��"+who->name()+"("+who->query("id")+")��"+verb+"Ƶ���򿪡�\n");
        return 1;
}
