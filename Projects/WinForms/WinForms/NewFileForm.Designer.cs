namespace WinForms
{
    partial class NewFileForm
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
            this.gridWidth = new System.Windows.Forms.NumericUpDown();
            this.gridHeight = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.columns = new System.Windows.Forms.Label();
            this.rows = new System.Windows.Forms.Label();
            this.gridColumns = new System.Windows.Forms.NumericUpDown();
            this.gridRows = new System.Windows.Forms.NumericUpDown();
            this.Okay = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.gridWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridColumns)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridRows)).BeginInit();
            this.SuspendLayout();
            // 
            // gridWidth
            // 
            this.gridWidth.Location = new System.Drawing.Point(251, 84);
            this.gridWidth.Name = "gridWidth";
            this.gridWidth.Size = new System.Drawing.Size(37, 20);
            this.gridWidth.TabIndex = 13;
            this.gridWidth.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            // 
            // gridHeight
            // 
            this.gridHeight.Location = new System.Drawing.Point(251, 58);
            this.gridHeight.Name = "gridHeight";
            this.gridHeight.Size = new System.Drawing.Size(37, 20);
            this.gridHeight.TabIndex = 12;
            this.gridHeight.Value = new decimal(new int[] {
            32,
            0,
            0,
            0});
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(135, 84);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(64, 15);
            this.label4.TabIndex = 11;
            this.label4.Text = "Grid Width";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(135, 58);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(69, 15);
            this.label3.TabIndex = 10;
            this.label3.Text = "Grid Height";
            // 
            // columns
            // 
            this.columns.AutoSize = true;
            this.columns.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.columns.Location = new System.Drawing.Point(135, 110);
            this.columns.Name = "columns";
            this.columns.Size = new System.Drawing.Size(56, 15);
            this.columns.TabIndex = 14;
            this.columns.Text = "Columns";
            // 
            // rows
            // 
            this.rows.AutoSize = true;
            this.rows.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rows.Location = new System.Drawing.Point(135, 136);
            this.rows.Name = "rows";
            this.rows.Size = new System.Drawing.Size(38, 15);
            this.rows.TabIndex = 15;
            this.rows.Text = "Rows";
            // 
            // gridColumns
            // 
            this.gridColumns.Location = new System.Drawing.Point(251, 110);
            this.gridColumns.Name = "gridColumns";
            this.gridColumns.Size = new System.Drawing.Size(37, 20);
            this.gridColumns.TabIndex = 16;
            this.gridColumns.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // gridRows
            // 
            this.gridRows.Location = new System.Drawing.Point(251, 136);
            this.gridRows.Name = "gridRows";
            this.gridRows.Size = new System.Drawing.Size(37, 20);
            this.gridRows.TabIndex = 17;
            this.gridRows.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // Okay
            // 
            this.Okay.Location = new System.Drawing.Point(176, 207);
            this.Okay.Name = "Okay";
            this.Okay.Size = new System.Drawing.Size(75, 23);
            this.Okay.TabIndex = 18;
            this.Okay.Text = "Okay";
            this.Okay.UseVisualStyleBackColor = true;
            this.Okay.Click += new System.EventHandler(this.Okay_Click);
            // 
            // NewFileForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(422, 276);
            this.Controls.Add(this.Okay);
            this.Controls.Add(this.gridRows);
            this.Controls.Add(this.gridColumns);
            this.Controls.Add(this.rows);
            this.Controls.Add(this.columns);
            this.Controls.Add(this.gridWidth);
            this.Controls.Add(this.gridHeight);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Name = "NewFileForm";
            this.Text = "NewFileForm";
            ((System.ComponentModel.ISupportInitialize)(this.gridWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridColumns)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridRows)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.NumericUpDown gridWidth;
        public System.Windows.Forms.NumericUpDown gridHeight;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label columns;
        private System.Windows.Forms.Label rows;
        public System.Windows.Forms.NumericUpDown gridColumns;
        public System.Windows.Forms.NumericUpDown gridRows;
        private System.Windows.Forms.Button Okay;
    }
}