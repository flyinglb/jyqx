      //warning.c ���淸�����
// Byp@MX

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
        string bec;
//      if(!wizardp(me))
//              return notify_fail("�����ʲô��\n");
                
        if( !arg || sscanf(arg, "%s because %s", arg, bec)!=2 )
                return notify_fail("ָ���ʽ��warning <id> because <ԭ��>\n");
        
        who = find_player(arg);
        
        if(!who) 
                return notify_fail("û�������ҡ�\n");
                
        if(wizardp(who)) //���Ըĳɸ߼���ʦ���¼�����
                return notify_fail("������ʦ��\n");
        if(who->query_temp("cmds_warning_const") > 0) {
                shout(HIR+ who->name() + HIR + "��Ϊ " + bec + " �����ؾ��棡\n"NOR);
                write(HIR+ who->name() + HIR + "��Ϊ " + bec + " �����ؾ��棡\n"NOR);
        } else {
                shout(HIR+ who->name() + HIR + "��Ϊ " + bec + " ������һ�Σ�\n"NOR);
                write(HIR+ who->name() + HIR + "��Ϊ " + bec + " ������һ�Σ�\n"NOR);
        }        
        who->add_temp("cmds_warning_const", 1);
        return 1;
}
