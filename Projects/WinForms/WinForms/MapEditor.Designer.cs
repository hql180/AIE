namespace WinForms
{
    partial class MapEditor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemNewFile = new System.Windows.Forms.ToolStripMenuItem();
            this.loadFile = new System.Windows.Forms.ToolStripMenuItem();
            this.TileMapMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tileHeight = new System.Windows.Forms.NumericUpDown();
            this.tileWidth = new System.Windows.Forms.NumericUpDown();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.setBackground = new System.Windows.Forms.Button();
            this.refreshButton = new System.Windows.Forms.Button();
            this.TileZoom = new System.Windows.Forms.Label();
            this.trackTileZoom = new System.Windows.Forms.TrackBar();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tileBox = new System.Windows.Forms.PictureBox();
            this.mapBox = new System.Windows.Forms.PictureBox();
            this.tilePanel = new System.Windows.Forms.Panel();
            this.MapPanel = new System.Windows.Forms.Panel();
            this.fileToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.gridHeight = new System.Windows.Forms.NumericUpDown();
            this.gridWidth = new System.Windows.Forms.NumericUpDown();
            this.trackGridZoom = new System.Windows.Forms.TrackBar();
            this.label3 = new System.Windows.Forms.Label();
            this.snakeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tileHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tileWidth)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackTileZoom)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tileBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.mapBox)).BeginInit();
            this.tilePanel.SuspendLayout();
            this.MapPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackGridZoom)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.SystemColors.Control;
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(840, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.loadFile,
            this.saveToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuItemNewFile});
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.openToolStripMenuItem.Text = "&Create";
            // 
            // menuItemNewFile
            // 
            this.menuItemNewFile.Name = "menuItemNewFile";
            this.menuItemNewFile.Size = new System.Drawing.Size(152, 22);
            this.menuItemNewFile.Text = "&New File";
            this.menuItemNewFile.Click += new System.EventHandler(this.menuItemNewFile_Click);
            // 
            // loadFile
            // 
            this.loadFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.TileMapMenu,
            this.fileToolStripMenuItem1,
            this.snakeToolStripMenuItem});
            this.loadFile.Name = "loadFile";
            this.loadFile.Size = new System.Drawing.Size(152, 22);
            this.loadFile.Text = "&Load";
            // 
            // TileMapMenu
            // 
            this.TileMapMenu.Name = "TileMapMenu";
            this.TileMapMenu.Size = new System.Drawing.Size(152, 22);
            this.TileMapMenu.Text = "&Tile Map";
            this.TileMapMenu.Click += new System.EventHandler(this.TileMapMenu_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.saveToolStripMenuItem.Text = "&Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // tileHeight
            // 
            this.tileHeight.Location = new System.Drawing.Point(122, 16);
            this.tileHeight.Name = "tileHeight";
            this.tileHeight.Size = new System.Drawing.Size(37, 20);
            this.tileHeight.TabIndex = 2;
            this.tileHeight.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            this.tileHeight.ValueChanged += new System.EventHandler(this.tileHeight_ValueChanged);
            // 
            // tileWidth
            // 
            this.tileWidth.Location = new System.Drawing.Point(122, 42);
            this.tileWidth.Name = "tileWidth";
            this.tileWidth.Size = new System.Drawing.Size(37, 20);
            this.tileWidth.TabIndex = 3;
            this.tileWidth.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            this.tileWidth.ValueChanged += new System.EventHandler(this.tileWidth_ValueChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.trackGridZoom);
            this.groupBox1.Controls.Add(this.setBackground);
            this.groupBox1.Controls.Add(this.refreshButton);
            this.groupBox1.Controls.Add(this.TileZoom);
            this.groupBox1.Controls.Add(this.trackTileZoom);
            this.groupBox1.Controls.Add(this.checkBox1);
            this.groupBox1.Controls.Add(this.gridWidth);
            this.groupBox1.Controls.Add(this.gridHeight);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.tileWidth);
            this.groupBox1.Controls.Add(this.tileHeight);
            this.groupBox1.Location = new System.Drawing.Point(12, 27);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(326, 184);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Tile Settings";
            // 
            // setBackground
            // 
            this.setBackground.Location = new System.Drawing.Point(186, 145);
            this.setBackground.Name = "setBackground";
            this.setBackground.Size = new System.Drawing.Size(114, 23);
            this.setBackground.TabIndex = 14;
            this.setBackground.Text = "Set Background";
            this.setBackground.UseVisualStyleBackColor = true;
            this.setBackground.Click += new System.EventHandler(this.setBackground_Click);
            // 
            // refreshButton
            // 
            this.refreshButton.Location = new System.Drawing.Point(6, 145);
            this.refreshButton.Name = "refreshButton";
            this.refreshButton.Size = new System.Drawing.Size(75, 23);
            this.refreshButton.TabIndex = 13;
            this.refreshButton.Text = "Refresh";
            this.refreshButton.UseVisualStyleBackColor = true;
            this.refreshButton.Click += new System.EventHandler(this.refreshButton_Click);
            // 
            // TileZoom
            // 
            this.TileZoom.AutoSize = true;
            this.TileZoom.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TileZoom.Location = new System.Drawing.Point(204, 16);
            this.TileZoom.Name = "TileZoom";
            this.TileZoom.Size = new System.Drawing.Size(62, 15);
            this.TileZoom.TabIndex = 12;
            this.TileZoom.Text = "Tile Zoom";
            // 
            // trackTileZoom
            // 
            this.trackTileZoom.Location = new System.Drawing.Point(186, 34);
            this.trackTileZoom.Minimum = 1;
            this.trackTileZoom.Name = "trackTileZoom";
            this.trackTileZoom.Size = new System.Drawing.Size(104, 45);
            this.trackTileZoom.TabIndex = 10;
            this.trackTileZoom.Value = 1;
            this.trackTileZoom.Scroll += new System.EventHandler(this.trackTileZoom_Scroll);
            this.trackTileZoom.ValueChanged += new System.EventHandler(this.trackTileZoom_ValueChanged);
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.checkBox1.Location = new System.Drawing.Point(6, 120);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(149, 19);
            this.checkBox1.TabIndex = 10;
            this.checkBox1.Text = "Show Collision objects";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(6, 42);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 15);
            this.label2.TabIndex = 5;
            this.label2.Text = "Tile Width";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(6, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 15);
            this.label1.TabIndex = 4;
            this.label1.Text = "Tile Height";
            // 
            // tileBox
            // 
            this.tileBox.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.tileBox.Cursor = System.Windows.Forms.Cursors.Default;
            this.tileBox.Location = new System.Drawing.Point(0, 0);
            this.tileBox.Name = "tileBox";
            this.tileBox.Size = new System.Drawing.Size(1000, 1000);
            this.tileBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.tileBox.TabIndex = 5;
            this.tileBox.TabStop = false;
            this.tileBox.Click += new System.EventHandler(this.tileBox_Click);
            this.tileBox.Paint += new System.Windows.Forms.PaintEventHandler(this.tileBox_Paint);
            this.tileBox.MouseMove += new System.Windows.Forms.MouseEventHandler(this.tileBox_MouseMove);
            this.tileBox.Resize += new System.EventHandler(this.tileBox_Resize);
            // 
            // mapBox
            // 
            this.mapBox.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.mapBox.Location = new System.Drawing.Point(3, 3);
            this.mapBox.Name = "mapBox";
            this.mapBox.Size = new System.Drawing.Size(320, 320);
            this.mapBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.mapBox.TabIndex = 6;
            this.mapBox.TabStop = false;
            this.mapBox.Paint += new System.Windows.Forms.PaintEventHandler(this.mapBox_Paint);
            this.mapBox.MouseClick += new System.Windows.Forms.MouseEventHandler(this.mapBox_MouseClick);
            this.mapBox.MouseMove += new System.Windows.Forms.MouseEventHandler(this.mapBox_MouseMove);
            // 
            // tilePanel
            // 
            this.tilePanel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.tilePanel.AutoScroll = true;
            this.tilePanel.Controls.Add(this.tileBox);
            this.tilePanel.Location = new System.Drawing.Point(12, 217);
            this.tilePanel.Name = "tilePanel";
            this.tilePanel.Size = new System.Drawing.Size(300, 304);
            this.tilePanel.TabIndex = 7;
            // 
            // MapPanel
            // 
            this.MapPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.MapPanel.AutoScroll = true;
            this.MapPanel.Controls.Add(this.mapBox);
            this.MapPanel.Location = new System.Drawing.Point(344, 28);
            this.MapPanel.Name = "MapPanel";
            this.MapPanel.Size = new System.Drawing.Size(484, 493);
            this.MapPanel.TabIndex = 8;
            // 
            // fileToolStripMenuItem1
            // 
            this.fileToolStripMenuItem1.AccessibleRole = System.Windows.Forms.AccessibleRole.OutlineButton;
            this.fileToolStripMenuItem1.Name = "fileToolStripMenuItem1";
            this.fileToolStripMenuItem1.Size = new System.Drawing.Size(152, 22);
            this.fileToolStripMenuItem1.Text = "&Save File";
            this.fileToolStripMenuItem1.Click += new System.EventHandler(this.fileToolStripMenuItem1_Click);
            // 
            // gridHeight
            // 
            this.gridHeight.Location = new System.Drawing.Point(122, 68);
            this.gridHeight.Name = "gridHeight";
            this.gridHeight.Size = new System.Drawing.Size(37, 20);
            this.gridHeight.TabIndex = 8;
            this.gridHeight.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            this.gridHeight.Visible = false;
            // 
            // gridWidth
            // 
            this.gridWidth.Location = new System.Drawing.Point(122, 94);
            this.gridWidth.Name = "gridWidth";
            this.gridWidth.Size = new System.Drawing.Size(37, 20);
            this.gridWidth.TabIndex = 9;
            this.gridWidth.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            this.gridWidth.Visible = false;
            // 
            // trackGridZoom
            // 
            this.trackGridZoom.Location = new System.Drawing.Point(186, 94);
            this.trackGridZoom.Minimum = 1;
            this.trackGridZoom.Name = "trackGridZoom";
            this.trackGridZoom.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.trackGridZoom.Size = new System.Drawing.Size(104, 45);
            this.trackGridZoom.TabIndex = 15;
            this.trackGridZoom.Value = 1;
            this.trackGridZoom.Scroll += new System.EventHandler(this.trackGridZoom_Scroll);
            this.trackGridZoom.ValueChanged += new System.EventHandler(this.trackGridZoom_ValueChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(204, 73);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 15);
            this.label3.TabIndex = 16;
            this.label3.Text = "Grid Zoom";
            // 
            // snakeToolStripMenuItem
            // 
            this.snakeToolStripMenuItem.Name = "snakeToolStripMenuItem";
            this.snakeToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.snakeToolStripMenuItem.Text = "Snake";
            this.snakeToolStripMenuItem.Click += new System.EventHandler(this.snakeToolStripMenuItem_Click);
            // 
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(840, 533);
            this.Controls.Add(this.MapPanel);
            this.Controls.Add(this.tilePanel);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.menuStrip1);
            this.Name = "MapEditor";
            this.Text = "MapEditor";
            this.Resize += new System.EventHandler(this.MapEditor_Resize);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tileHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tileWidth)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackTileZoom)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tileBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.mapBox)).EndInit();
            this.tilePanel.ResumeLayout(false);
            this.MapPanel.ResumeLayout(false);
            this.MapPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackGridZoom)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.NumericUpDown tileHeight;
        private System.Windows.Forms.NumericUpDown tileWidth;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox tileBox;
        private System.Windows.Forms.PictureBox mapBox;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menuItemNewFile;
        private System.Windows.Forms.ToolStripMenuItem loadFile;
        private System.Windows.Forms.ToolStripMenuItem TileMapMenu;
        private System.Windows.Forms.Panel tilePanel;
        private System.Windows.Forms.Panel MapPanel;
        private System.Windows.Forms.Label TileZoom;
        private System.Windows.Forms.TrackBar trackTileZoom;
        private System.Windows.Forms.Button refreshButton;
        private System.Windows.Forms.Button setBackground;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem1;
        private System.Windows.Forms.NumericUpDown gridWidth;
        private System.Windows.Forms.NumericUpDown gridHeight;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TrackBar trackGridZoom;
        private System.Windows.Forms.ToolStripMenuItem snakeToolStripMenuItem;
    }
}