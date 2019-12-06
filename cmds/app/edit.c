// edit.c
// modified by wind

inherit F_CLEAN_UP;

int main(object me, string file)
{
        if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");
        if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");
        
        file = resolve_path(me->query("cwd"), file);
        
        seteuid(geteuid(me));
        
        if (!(int)SECURITY_D->valid_write(file, me, "write_file"))
                return notify_fail("�༭������Ч���ļ�����\n");
        
        log_file("edit/"+geteuid(me), sprintf("edit %s %s\n", file, ctime(time())) );

        ed(resolve_path(me->query("cwd"), file));
        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : edit <����>, edit here
���ô�һָ���ֱ�������ϱ༭������
                /��ǰ����ƥ����
                ?�������ƥ����
                =��ʾ��ǰ��������
                a�ڵ�ǰ�еĺ������
                A��'a'����
                c�޸ĵ�ǰ�У��滻��ѯ�ı�
                dɾ��һ�л����
                e����һ���ļ����ǵ�ǰ�ļ�
                E��'e'���ƣ���ֻ���ļ������޸�֮����Ч
                f��ʾ/�ı䵱ǰ�ļ����ļ���
                g��������ƥ�����ִ��ĳ������
                h����
                i�ڵ�ǰ��ǰ�����ַ�
                k��һ���ַ���ǵ�ǰ��
                l�г�һ�л���У��������ַ���
                m�ƶ�һ�л���е�ָ����λ�ã��кţ�
                n����к�
                Oͬ'i'
                oͬ 'a'
                p�г�һ����Χ����
                q�˳�
                Q�˳������Ҳ���
                r���ļ�β����ָ���к���������ļ�
                s�������滻
                set��ѯ���ı��洢ĳ���趨ѡ��
                t����һ�л��е�ָ������
                v�������Բ�ƥ�����ִ��ĳ������
                x���ļ����˳�
                wд�뵱ǰ�ļ�����ָ���ļ������ø��ǳ)
                W��'w'���ƣ�����׷��
                z��ʾ20�У����� . + - ���ֱ��
                Z��ʾ40�У����� . + - ���ֱ��

HELP
    );
    return 1;
}

