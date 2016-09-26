using UnityEngine;
using UnityEditor;
using System.Collections;

[CustomEditor(typeof(Item))]
public class ItemEditor : Editor
{
    private static bool foldout;

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
    }

    public static void DrawItemEditor(Item item, bool foldout)
    {
        
    }

}
